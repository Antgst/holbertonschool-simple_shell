# 🐚 C - Simple Shell — Holberton School Rennes

## 📝 Description
This project is a **simple UNIX command interpreter** (a minimal shell) built in **C**.  
It reproduces the core behavior of `/bin/sh` in both **interactive** and **non-interactive** modes: read input, parse commands, resolve programs using `PATH`, create child processes, execute binaries with `execve`, and match `sh` error behavior (with one key difference: the program name in errors must match `argv[0]`).

---

## 🎯 Learning Objectives
By the end of this project, we are expected to be able to explain (without Google):

### General
- Who designed and implemented the original Unix operating system
- Who wrote the first version of the UNIX shell
- Who invented the B programming language (predecessor of C)
- Who Ken Thompson is
- How a shell works
- What `pid` and `ppid` are
- How to manipulate the environment of the current process
- The difference between a function and a system call
- How to create processes
- The three prototypes of `main`
- How the shell uses the `PATH` to find programs
- How to execute another program with the `execve` system call
- How to suspend execution of a process until one of its children terminates
- What EOF (“end-of-file”) means

---

## ⚙️ Requirements
- OS: Ubuntu 20.04 LTS
- Compiler: `gcc` with `-Wall -Werror -Wextra -pedantic -std=gnu89`
- Allowed editors: `vi`, `vim`, `emacs`
- Code style: **Betty** (`betty-style.pl` and `betty-doc.pl`)
- No memory leaks
- Max **5 functions per file**
- All header files must be **include-guarded**
- Use system calls only when needed (and know why)

---

## ✅ Output Rules
Unless specified otherwise:
- Output must match `/bin/sh` (same standard output and error output)
- Only difference: when printing errors, the program name must match **your `argv[0]`**

Example with `sh`:
```bash
echo "qwerty" | /bin/sh
# /bin/sh: 1: qwerty: not found

echo "qwerty" | /bin/../bin/sh
# /bin/../bin/sh: 1: qwerty: not found
```

Same error with your program `hsh`:
```bash
echo "qwerty" | ./hsh
# ./hsh: 1: qwerty: not found

echo "qwerty" | ./././hsh
# ./././hsh: 1: qwerty: not found
```

---

## 🧰 Allowed Functions & System Calls
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

## 🛠️ Compilation
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

---

## ▶️ Usage
### Interactive mode
```bash
./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
```

### Non-interactive mode
```bash
echo "/bin/ls" | ./hsh
```

Or with a file:
```bash
cat test_ls_2 | ./hsh
```

---

## 🧪 Testing & Quality
Recommended checks:
- Compare behavior with `/bin/sh` for:
  - command not found errors
  - empty lines / spaces / tabs
  - `PATH` resolution
  - EOF handling (`Ctrl+D`)
  - exit status behavior
- Memory: no leaks expected
```bash
valgrind --leak-check=full --show-leak-kinds=all ./hsh
```

---

## 📚 Resources
- Unix shell
- Thompson shell
- Ken Thompson
- Holberton concept page: “Everything you need to know to start coding your own shell”
- `man sh` (run `/bin/sh` too)
- `man 2 execve`, `man 2 fork`, `man 2 wait`, `man 3 getline`, `man 3 strtok`, etc.

---

## 👥 Team
* Antoine Gousset – GitHub: [Antgst](https://github.com/Antgst)  
* Yonas Houriez – GitHub: [Ausaryu](https://github.com/Ausaryu)

---

## 📌 Notes
- The checker is released near the end of the project: build a solid test suite early.
- After the deadline, you may need to fork the repository to your GitHub account for checker correction.
