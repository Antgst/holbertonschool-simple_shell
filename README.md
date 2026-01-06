# 🐚 Simple Shell (Holberton)

A minimal UNIX command line interpreter written in **C**, built for the **Holberton “Simple Shell”** project.

---

## ✨ Features (Implemented)

- **Interactive mode** with prompt: `($) `
- **Non-interactive mode** (reads commands from `stdin`)
- **Tokenization** (splits input into `argv`)
- **PATH resolution**
  - Searches `PATH` **only if** the command does **not** contain `/`
  - Handles **empty PATH entries** (`::`, leading/trailing `:`) as current directory `.`
- **Environment support**
  - Builtin: `env` (prints the environment)
- Exit support
  - Builtin: `exit` (exits with the last command status)

---

## 🚫 Not Implemented (Project Scope)

- Pipes: `|`
- Separators: `;`
- Redirections: `>`, `<`, `>>`, `2>`
- Quotes / escaping: `"..."`, `'...'`, `\`
- Globbing / wildcards: `*`
- Job control, history, aliases
- Builtins like `cd`, `setenv`, `unsetenv`

---

## ✅ Requirements

- Ubuntu 20.04 LTS
- Compilation:
  - `gcc -Wall -Werror -Wextra -pedantic -std=gnu89`
- Betty style compliant
- No memory leaks (Valgrind-ready)
- Max **5 functions per file**

---

## 🧱 Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

---

## 🚀 Usage

### 🧑‍💻 Interactive Mode
```text
$ ./hsh
($) /bin/ls
...
($) env
USER=...
PATH=...
...
($) exit
$
```

### 🤖 Non-Interactive Mode
```bash
echo "/bin/ls" | ./hsh
cat file_with_commands | ./hsh
```

---

## 🧨 Error Handling & Exit Status

This shell aims to behave like `/bin/sh` for basic execution.

- **Command not found**
  - Prints:
    - `<shell_name>: <line>: <command>: not found`
  - Returns status: **127**

- **Permission denied / Is a directory**
  - Returns status: **126**

- The shell process exits with the **status of the last executed command**, like `/bin/sh`.

---

## 🗂️ Project Structure

| 📄 File | 📌 Purpose |
|--------|------------|
| `shell.c` | Main loop: prompt → read → tokenize → builtins → execute |
| `tokenize_line.c` | Splits input into tokens (`argv`) |
| `exec.c` | `fork()` + `execve()` + `waitpid()` + status propagation |
| `pathmaker.c` | Builds the executable path using `PATH` (handles empty entries) |
| `getenv.c` | `_getenv()` helper (reads from `environ`) |
| `print_env.c` | Prints environment variables for `env` |
| `_strerror.c` | Error message helper (`ENOENT` -> `"not found"`, else `strerror`) |
| `shell.h` | Headers, includes, prototypes |
| `man_1_simple_shell` | Manual page |
| `AUTHORS` | Project authors |

---

## 📚 Man Page

```bash
man ./man_1_simple_shell
```

---

## 🧪 Quick Testing

```bash
# interactive
./hsh

# non-interactive
echo "ls" | ./hsh

# not found -> 127
echo "qwerty" | ./hsh
echo $?
```

---

## 👥 Authors
* Yonas Houriez – GitHub: [Ausaryu](https://github.com/Ausaryu)  
* Antoine Gousset – GitHub: [Antgst](https://github.com/Antgst)

See `AUTHORS`.
