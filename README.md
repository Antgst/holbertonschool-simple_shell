# 🐚 Simple Shell (Holberton)

A minimal UNIX command line interpreter written in **C** for the Holberton **Simple Shell** project.

---

## 📌 Description

This project implements a small shell that:
- reads a command line from standard input (interactive or non-interactive),
- tokenizes it into an `argv[]` array,
- resolves the command path (using `PATH` when appropriate),
- executes programs using `fork()` + `execve()`,
- waits for completion using `waitpid()`,
- provides the built-ins `exit` and `env`.

Per the subject, the goal is to match **`/bin/sh` output and error output**, with the only difference that the error prefix must be the shell program name (`argv[0]`).

---

## ✨ Features (Implemented)

- **Interactive mode** (TTY stdin): prints a prompt and waits for commands
- **Non-interactive mode**: reads commands from `stdin` (pipes / redirected input)
- **Tokenization**: splits input on spaces/tabs into `argv`
- **PATH resolution**
  - searches `PATH` only if the command does **not** contain `/`
  - does **not** call `fork()` if the command cannot be found
- **Built-ins**
  - `exit` — exits the shell (no argument handling required by the subject)
  - `env` — prints the environment

---

## 🚫 Not Implemented (Project Scope)

- Pipes: `|`
- Separators: `;`, `&&`, `||`
- Redirections: `>`, `<`, `>>`, `2>`
- Quotes / escaping: `"..."`, `'...'`, `\`
- Globbing / wildcards: `*`
- History, aliases, job control
- Built-ins like `cd`, `setenv`, `unsetenv`

---

## ✅ Requirements (Subject)

- OS: **Ubuntu 20.04 LTS**
- Compilation:
  - `gcc -Wall -Werror -Wextra -pedantic -std=gnu89`
- **Betty** style compliant
- **No memory leaks**
- Max **5 functions per file**
- Header files must be **include guarded**
- Use system calls only when needed

---

## 🧱 Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
