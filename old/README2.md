# Simple Shell – Custom simple shell (Holberton School project)

## 📌 Description
A **simple UNIX command interpreter** written in **C**, designed to mimic the core behavior of `/bin/sh` in both **interactive** and **non-interactive** modes.  
It reads input, tokenizes commands, resolves executables using `PATH`, spawns processes with `fork()`, runs programs with `execve()`, and waits for completion with `wait()`/`waitpid()`.

✅ Output and error behavior must match `sh`, with one key difference: **error messages must print the program name exactly as `argv[0]`**.

---

## 📐 Prototype
```c
int main(int ac, char **av, char **env);
```

---

## 🧩 How it works
1. **Read input**
   - If interactive (`isatty(STDIN_FILENO)`), display a prompt and wait for input.
   - Read a full line with `getline()`.
   - Handle **EOF** (`Ctrl+D`) properly.

2. **Parse**
   - Clean the line and split it into tokens (command + args) using delimiters (spaces/tabs/newlines).
   - Ignore empty lines.

3. **Resolve command**
   - If the command contains `/`, treat it as a direct path and check access.
   - Otherwise, search through each directory in `PATH` to find an executable match.

4. **Execute**
   - `fork()` a child process.
   - In the child: call `execve()` to run the program.
   - In the parent: wait for the child to finish with `wait()`/`waitpid()`.

5. **Error handling**
   - Match `/bin/sh` formatting, except the program name must equal `argv[0]`.

---

## 🏗️ Supported format specifiers
Not applicable for this project (this is **not** a `_printf` project).

---

### List
- Not applicable.

---

### Summary table
- Not applicable.

---

## 🎯 Return value
- The shell returns the **exit status of the last executed command**.
- “Command not found” commonly returns **127** (shell convention).
- Other errors follow standard UNIX exit status behavior depending on the failure.

---

### Examples (return values)
- `0` → command executed successfully  
- `127` → command not found  
- other values → propagated from the executed program or set by error handling

---

## 🧰 Requirements
- OS: Ubuntu 20.04 LTS
- Compiler: `gcc` with `-Wall -Werror -Wextra -pedantic -std=gnu89`
- Allowed editors: `vi`, `vim`, `emacs`
- A `README.md` file at the root is mandatory
- Code style: **Betty** (`betty-style.pl`, `betty-doc.pl`)
- No memory leaks
- Max **5 functions per file**
- All header files must be **include-guarded**
- Use system calls only when needed
- Allowed functions/syscalls include:
  - all functions from `<string.h>`
  - `access`, `chdir`, `close`
  - `closedir`, `opendir`, `readdir`
  - `execve`
  - `exit`, `_exit`
  - `fflush`
  - `fork`
  - `free`, `malloc`
  - `getcwd`
  - `getline`
  - `getpid`
  - `isatty`
  - `kill`
  - `open`, `read`, `write`
  - `perror`, `printf`, `fprintf`, `vfprintf`, `sprintf`, `putchar`
  - `signal`
  - `stat`, `lstat`, `fstat`
  - `strtok`
  - `wait`, `waitpid`, `wait3`, `wait4`

---

## ⚙️ Compilation
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

---

## 🛠️ Usage

### Simple example
```bash
./hsh
($) /bin/ls
hsh main.c shell.c
($) exit
```

### More examples (per type)

**Non-interactive mode**
```bash
echo "/bin/ls" | ./hsh
```

**With a file**
```bash
cat test_ls_2 | ./hsh
```

**Error output rule (`argv[0]`)**
```bash
echo "qwerty" | ./././hsh
# ./././hsh: 1: qwerty: not found
```

---

## 📁 Project files
Typical structure (may vary depending on the team implementation):
- `main.c` — entry point, mode detection (interactive vs non-interactive)
- `shell.c` / `loop.c` — main read/parse/execute loop
- `parser.c` — tokenization/splitting helpers
- `path.c` — `PATH` lookup and command resolution
- `execute.c` — `fork()` / `execve()` / `wait()` logic
- `env.c` — environment helpers (if implemented)
- `errors.c` — error formatting/output
- `*.h` — headers (include-guarded)
- `docs/` — flowchart, man page, extra docs (if present)

---

## 🔁 Flowchart
![SIMPLE SHELL flowchart](LINK DANS /DOCS)

---

## 📖 Man page
If included, the man page should cover:
- Name / synopsis (`hsh`)
- Interactive vs non-interactive behavior
- Supported built-ins (if any)
- Exit statuses
- Error formatting rules (argv[0] requirement)

---

## 🧪 Testing

### Betty style (Holberton C coding style)
```bash
betty *.c *.h
```

### Valgrind (optional, for memory checks)
```bash
valgrind --leak-check=full --show-leak-kinds=all ./hsh
```

### Manual tests
Compare behavior against `/bin/sh`:
- Basic commands: `ls`, `pwd`, `env`
- Invalid command: `qwerty`
- Leading/trailing spaces, tabs, empty lines
- EOF handling (`Ctrl+D`)
- Non-interactive pipelines:
  - `echo "/bin/ls" | ./hsh`
  - `cat file | ./hsh`

---

## ⚠️ Limitations
Common limitations (depends on project progress/choices):
- Limited or no built-ins unless explicitly implemented (e.g., `cd`, `exit`, `env`)
- No advanced features unless implemented:
  - pipes (`|`), redirections (`>`, `<`), chaining (`&&`, `||`), globbing (`*`)
- Basic tokenization only (space-delimited parsing)

---

## 👥 Authors
* Antoine Gousset – GitHub: [Antgst](https://github.com/Antgst)  
* Yonas Houriez – GitHub: [Ausaryu](https://github.com/Ausaryu)

