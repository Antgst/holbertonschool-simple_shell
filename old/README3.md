# Simple Shell – Custom simple shell (Holberton School project)

## 📌 Description
A **simple UNIX command interpreter** written in **C**, built as part of the **Holberton School Rennes** curriculum.

This shell aims to reproduce the essential behavior of `/bin/sh`:
- Works in **interactive mode** (prompt + user input)
- Works in **non-interactive mode** (commands piped from `stdin`)
- Parses a command line into tokens (command + arguments)
- Resolves executables via **absolute/relative paths** or via the **`PATH`** environment variable
- Creates child processes with `fork()`, executes programs with `execve()`, and synchronizes using `wait()` / `waitpid()`
- Matches `/bin/sh` output and error output, with one key difference:
  - **Error messages must display the program name exactly as `argv[0]`** (e.g. `./././hsh: 1: qwerty: not found`)

---

## 📐 Prototype
```c
int main(int ac, char **av, char **env);
```

---

## 🧩 How it works
### 1) Detect mode (interactive vs non-interactive)
- Use `isatty(STDIN_FILENO)`:
  - `true` → interactive: display a prompt (e.g. `($) `)
  - `false` → non-interactive: read and execute commands from `stdin` until EOF

### 2) Read a full line
- Use `getline()` to read a complete line (including spaces)
- Handle:
  - empty lines (ignore)
  - EOF (`Ctrl + D` in interactive mode / end of piped input in non-interactive mode)

### 3) Tokenize (command + args)
- Split the line into tokens using delimiters like spaces, tabs, and newlines
- Build an `argv`-style array:
  - `argv[0]` = command
  - `argv[1..]` = arguments
  - last = `NULL`

### 4) Resolve the executable
- If the command contains a `/`:
  - treat it as a direct path and verify it (e.g. with `access()`)
- Otherwise:
  - read `PATH`, iterate over directories, build candidate paths, and check for an executable match

### 5) Execute (fork → execve → wait)
- `fork()`:
  - child → `execve()` (replace process image with the program)
  - parent → `wait()`/`waitpid()` (suspend until the child terminates)
- Preserve exit status behavior: the shell should return the status of the last command executed

### 6) Error handling (sh-compatible output)
- If a command is not found, print a `sh`-style error message, but using your own `argv[0]`
- Example rule:
  - `/bin/sh: 1: qwerty: not found`
  - `./hsh: 1: qwerty: not found`

---

## 🏗️ Supported format specifiers
Not applicable (this is **not** a `_printf` project).  
Below is what the shell supports instead (baseline expectations for the project).

---

### List
- ✅ Interactive mode prompt + command execution
- ✅ Non-interactive execution via `stdin` piping
- ✅ Execute commands using:
  - absolute paths (e.g. `/bin/ls`)
  - relative paths (e.g. `./myprog`)
  - `PATH` resolution (e.g. `ls`)
- ✅ Arguments support (e.g. `ls -l /tmp`)
- ✅ Proper EOF handling (`Ctrl+D`)
- ✅ Error messages matching `sh` formatting (program name = `argv[0]`)
- ✅ No memory leaks (Valgrind-clean expected)

---

### Summary table
| Feature | Expected behavior |
|--------:|-------------------|
| Interactive mode | Prompt + executes commands until `exit`/EOF |
| Non-interactive mode | Reads from `stdin` and executes each line |
| PATH resolution | Finds executables from `PATH` directories |
| Process handling | `fork()` → `execve()` → `wait()`/`waitpid()` |
| Errors | Same as `/bin/sh`, but program name is your `argv[0]` |
| Memory | No leaks |

---

## 🎯 Return value
The shell should return the **exit status of the last executed command**.

Common `sh`-style conventions (useful for debugging/testing):
- `0` → success
- `127` → command not found
- `126` → found but not executable / permission problem (common shell convention)

---

### Examples (return values)
- `0` → `/bin/ls` runs correctly  
- `127` → `qwerty` not found  
- other values → forwarded from the executed program

---

## 🧰 Requirements
- **OS:** Ubuntu 20.04 LTS
- **Compiler:** `gcc` with `-Wall -Werror -Wextra -pedantic -std=gnu89`
- **Editors:** `vi`, `vim`, `emacs`
- **Mandatory:** a `README.md` at the project root
- **Style:** Betty (`betty-style.pl` and `betty-doc.pl`)
- **Memory:** no leaks
- **Architecture constraints:** max **5 functions per file**
- **Headers:** must be include-guarded
- **System calls:** use only when needed (and know why)

### Allowed functions & syscalls (project whitelist)
- All functions from `<string.h>`
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
### Simple example (interactive)
```bash
./hsh
($) /bin/ls
hsh main.c shell.c
($) exit
```

### More examples (per type)
#### Non-interactive mode
```bash
echo "/bin/ls" | ./hsh
```

#### Piped file input
```bash
cat test_ls_2 | ./hsh
```

#### Error output rule (`argv[0]`)
```bash
echo "qwerty" | ./././hsh
# ./././hsh: 1: qwerty: not found
```

---

## 📁 Project files
Typical structure (update to match your repository):
- `main.c` — entry point, mode detection (interactive vs non-interactive)
- `shell.c` / `loop.c` — main read/parse/execute loop
- `parser.c` — tokenization helpers
- `path.c` — `PATH` parsing and executable resolution
- `execute.c` — `fork()` / `execve()` / `wait()` logic
- `env.c` — environment helpers (if implemented)
- `errors.c` — error formatting/output helpers
- `*.h` — header files (include-guarded)
- `docs/` — flowchart, documentation assets
- `man_1_simple_shell` — manual page (if included)

---

## 🔁 Flowchart
![SIMPLE SHELL flowchart](docs/flowchart.png)

---

## 📖 Man page
If your project includes a man page file (commonly `man_1_simple_shell`), you can test it like this:
```bash
man ./man_1_simple_shell
```

It should describe:
- Synopsis (`hsh`)
- Interactive vs non-interactive usage
- Environment / PATH behavior
- Exit statuses
- Error output rules (program name = `argv[0]`)

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
Compare against `/bin/sh`:
- basic commands: `ls`, `pwd`, `env`
- invalid command: `qwerty`
- spacing edge cases: leading/trailing spaces, multiple spaces/tabs
- empty lines
- EOF handling: `Ctrl+D`
- non-interactive:
  - `echo "/bin/ls" | ./hsh`
  - `cat file | ./hsh`

---

## ⚠️ Limitations
Depends on implemented tasks, but typical limitations (unless explicitly added):
- No advanced shell features by default:
  - pipes (`|`), redirections (`>`, `<`), chaining (`&&`, `||`), globbing (`*`)
- Parsing is typically basic (space-delimited tokenization)
- Built-ins may be limited (often at least `exit`; others depend on your implementation)

---

## 👥 Authors
* Antoine Gousset – GitHub: [Antgst](https://github.com/Antgst)  
* Yonas Houriez – GitHub: [Ausaryu](https://github.com/Ausaryu)
