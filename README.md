# 🐚 Simple Shell (Holberton)

Minimal UNIX command line interpreter written in **C** (Holberton *simple_shell* project).

---

## 📌 Description

`hsh` reads commands from **stdin**, tokenizes them into an `argv[]` array, resolves the executable
(using `PATH` when needed), then runs programs with `fork()` + `execve()` and waits with `waitpid()`.

Project requirement (subject): output and error output should match **`/bin/sh`**, except the error prefix must be `argv[0]`.

This repository implements:
- interactive and non-interactive execution
- commands **with arguments**
- `PATH` resolution
- built-ins: `exit`, `env`

---

## ✅ Implemented

### Modes
- **Interactive** (`isatty(stdin)`): prints a prompt, reads a line, executes, repeats
- **Non-interactive**: reads commands from stdin (pipes / redirected input)

### Parsing
- Tokenization on **spaces and tabs**
- Arguments are supported (`ls -l /tmp`)

### Execution
- Uses `fork()` + `execve()`
- Returns the **last command status**
- Does **not** call `fork()` when a command cannot be resolved (no executable path found)

### Built-ins
- `exit` — exits the shell (**no argument handling**)
- `env` — prints the environment

---

## 🚫 Not implemented (scope)

- Pipes `|`
- Command separators `;`, `&&`, `||`
- Redirections `>`, `<`, `>>`, `2>`
- Quotes / escaping
- Globbing (`*`)
- History, aliases, job control
- Built-ins like `cd`, `setenv`, `unsetenv`

---

## ⚙️ Requirements (subject)

- Ubuntu **20.04 LTS**
- `gcc -Wall -Werror -Wextra -pedantic -std=gnu89`
- Betty style compliant
- No memory leaks
- Max 5 functions per file
- Include-guarded headers

---

## 🧱 Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

---

## 🚀 Usage

### Interactive
> **Note:** in this repository the prompt printed is `$ `.

```text
$ ./hsh
$ /bin/ls
AUTHORS  exec.c  getenv.c  pathmaker.c  print_env.c  shell.c  shell.h  tokenize_line.c
$ exit
$
```

### Non-interactive
```bash
echo "/bin/ls" | ./hsh
printf "ls -l /tmp\nwhoami\n" | ./hsh
```

---

## 🧭 Flowchart

![Simple Shell Flowchart](docs/Flowchart_simple_shell.pdf)

## 🧨 Errors & exit status (current behavior)

### Command not found
Printed on **stderr**:
```text
<shell_name>: <line_number>: <command>: not found
```
Returned status: **127**

### `execve()` failure after a path was built/found
Printed on **stderr** (current message):
```text
<shell_name>: <line_number>: <command>: acces denied
```
Returned status: **126**

### Signals
If the child terminates due to a signal, the returned status is:
`128 + signal_number`

---

## ⚠️ Notes vs `/bin/sh` requirement (subject)

The subject asks for the same output/error output as `/bin/sh`.
This repository matches the main format for “not found”, but there are known differences:
- Prompt is `$ ` (subject examples show `($) `)
- `env` does not update the stored “last status” in the main loop
- A non-executable command **with a slash** (e.g. `./file_without_x`) is treated as “not found” (127) by path resolution, while `/bin/sh` typically reports “Permission denied” (126)

If you want strict `/bin/sh` parity, these points should be aligned in code.

---

## 🗂️ Repository files

| File | Purpose |
|------|---------|
| `shell.c` | Main loop: prompt → `getline()` → tokenize → builtins → execute |
| `tokenize_line.c` | Tokenization into `argv[]` (spaces/tabs) |
| `pathmaker.c` | Resolve executable path (`PATH` search) |
| `exec.c` | `fork()` + `execve()` + `waitpid()` + status propagation |
| `getenv.c` | `_getenv()` helper |
| `print_env.c` | `env` builtin output |
| `_strlen.c` `_strcmp.c` `_strcpy.c` `_strdup.c` `_strchr.c` | small string helpers |
| `shell.h` | prototypes / includes |
| `man_1_simple_shell` | man page (to be installed / viewed with `man`) |
| `AUTHORS` | contributors |

---

## 📚 Man page

```bash
man ./man_1_simple_shell
```

---

## 🧪 Quick tests

```bash
# not found -> 127
echo "qwerty" | ./hsh
echo $?

# args + PATH resolution
echo "ls -l /tmp" | ./hsh

# env builtin
echo "env" | ./hsh
```

---

## 👥 Authors
* Yonas Houriez – GitHub: [Ausaryu](https://github.com/Ausaryu)  
* Antoine Gousset – GitHub: [Antgst](https://github.com/Antgst)

See `AUTHORS`.
