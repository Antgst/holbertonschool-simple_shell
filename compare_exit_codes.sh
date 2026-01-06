#!/usr/bin/env bash
set -u

HSH="${HSH:-./hsh}"
SH="${SH:-/bin/sh}"

if [[ ! -x "$HSH" ]]; then
  echo "ERROR: '$HSH' introuvable ou non exécutable (export HSH=./hsh)"
  exit 1
fi
if [[ ! -x "$SH" ]]; then
  echo "ERROR: '$SH' introuvable (export SH=/bin/sh)"
  exit 1
fi

TMPDIR="$(mktemp -d)"
trap 'chmod -R 755 "$TMPDIR" >/dev/null 2>&1 || true; rm -rf "$TMPDIR"' EXIT

WORK="$TMPDIR/work"
mkdir -p "$WORK"
cp "$HSH" "$WORK/hsh"

# cmd exécutable dans le cwd
cat > "$WORK/cmd.sh" <<'EOF'
#!/bin/sh
exit 0
EOF
chmod +x "$WORK/cmd.sh"

# fichier non exécutable
echo 'exit 0' > "$WORK/noexec"
chmod 644 "$WORK/noexec"

# dossier
mkdir -p "$WORK/dir"

# PATH non accessible
mkdir -p "$TMPDIR/noperm"
chmod 000 "$TMPDIR/noperm" >/dev/null 2>&1 || true

# helper: exécuter une "session" et récupérer code retour
run_session() {
  local shell_kind="$1"   # sh|hsh
  local envcmd="$2"       # ex: env -i PATH="..."
  local input="$3"        # lignes de commandes

  ( cd "$WORK" && \
    if [[ "$shell_kind" == "sh" ]]; then
      # IMPORTANT: sh lancé en chemin absolu pour survivre à PATH=""
      eval "$envcmd" "$SH" <<< "$input" >/dev/null 2>&1
    else
      eval "$envcmd" ./hsh <<< "$input" >/dev/null 2>&1
    fi
  )
  echo $?
}

pass=0
fail=0

check_case() {
  local title="$1"
  local envcmd="$2"
  local input="$3"
  local expect_mode="$4" # "match" ou "custom"
  local expected="$5"    # si custom: code attendu pour hsh (ex: 2 pour exit task)

  local rc_sh rc_hsh
  rc_sh="$(run_session sh  "$envcmd" "$input")"
  rc_hsh="$(run_session hsh "$envcmd" "$input")"

  if [[ "$expect_mode" == "match" ]]; then
    if [[ "$rc_sh" == "$rc_hsh" ]]; then
      printf "PASS: %-35s sh=%s hsh=%s\n" "$title" "$rc_sh" "$rc_hsh"
      ((pass++))
    else
      printf "FAIL: %-35s sh=%s hsh=%s\n" "$title" "$rc_sh" "$rc_hsh"
      ((fail++))
    fi
  else
    # custom expected for hsh
    if [[ "$rc_hsh" == "$expected" ]]; then
      printf "PASS: %-35s hsh=%s (expected %s) [sh=%s]\n" "$title" "$rc_hsh" "$expected" "$rc_sh"
      ((pass++))
    else
      printf "FAIL: %-35s hsh=%s (expected %s) [sh=%s]\n" "$title" "$rc_hsh" "$expected" "$rc_sh"
      ((fail++))
    fi
  fi
}

# =========================
# TESTS
# =========================

# 0) exit builtin (si ton projet exige exit=2, on met custom)
check_case "builtin exit" \
  'env -i PATH="/bin:/usr/bin"' \
  $'exit\n' \
  custom 2

# 1) commande OK -> rc 0
check_case "command ok (/bin/true)" \
  'env -i PATH="/bin:/usr/bin"' \
  $'/bin/true\n' \
  match ""

# 2) not found -> 127
check_case "not found (no_such_cmd)" \
  'env -i PATH="/bin:/usr/bin"' \
  $'no_such_cmd_123\n' \
  match ""

# 3) PATH absent: 'ls' doit être not found -> 127 (sh dépend parfois, mais on compare quand même)
check_case "PATH absent: ls" \
  'env -i' \
  $'ls\n' \
  match ""

# 4) PATH vide: ls -> not found
check_case "PATH empty: ls" \
  'env -i PATH=""' \
  $'ls\n' \
  match ""

# 5) chemin relatif explicite ok
check_case "relative ./cmd.sh ok" \
  'env -i PATH="/bin:/usr/bin"' \
  $'./cmd.sh\n' \
  match ""

# 6) fichier non exécutable -> 126 (Permission denied)
check_case "non-executable ./noexec" \
  'env -i PATH="/bin:/usr/bin"' \
  $'./noexec\n' \
  match ""

# 7) dossier -> 126 (Permission denied / Is a directory selon sh, mais rc 126)
check_case "directory ./dir" \
  'env -i PATH="/bin:/usr/bin"' \
  $'./dir\n' \
  match ""

# 8) PATH avec entrée vide => '.' (":/bin") ; cmd.sh doit être trouvable sans ./ -> rc 0
check_case "PATH has empty entry => . (cmd.sh)" \
  'env -i PATH=":/bin"' \
  $'cmd.sh\n' \
  match ""

# 9) PATH contient un dossier non accessible + commande absente
# sh renvoie souvent 126 (Permission denied) ici. On compare.
check_case "PATH noperm:/bin + not found" \
  "env -i PATH=\"$TMPDIR/noperm:/bin\"" \
  $'no_such_cmd_123\n' \
  match ""

echo "=================================================="
echo "DONE. PASS=$pass FAIL=$fail"
if [[ $fail -ne 0 ]]; then
  exit 1
fi
exit 0
