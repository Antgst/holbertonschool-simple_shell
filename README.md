# 📘 C - Simple Shell

## 📌 Description

_No description detected._

---

## 📚 Resources

**Read or watch**:



- [Unix shell](https://en.wikipedia.org/wiki/Unix_shell)

- [Thompson shell](https://en.wikipedia.org/wiki/Thompson_shell)

- [Ken Thompson](https://en.wikipedia.org/wiki/Ken_Thompson)

- **Everything you need to know to start coding your own shell** concept page



**man or help**:



- `sh` (*Run `sh` as well*)

---

## 🎯 Learning Objectives

At the end of this project, you are expected to be able to [explain to anyone](https://fs.blog/feynman-learning-technique/), __without the help of Google__:



### General



- Who designed and implemented the original Unix operating system

- Who wrote the first version of the UNIX shell

- Who invented the B programming language (the direct predecessor to the C programming language)

- Who is Ken Thompson

- How does a shell work

- What is a pid and a ppid

- How to manipulate the environment of the current process

- What is the difference between a function and a system call

- How to create processes

- What are the three prototypes of `main`

- How does the shell use the `PATH` to find the programs

- How to execute another program with the `execve` system call

- How to suspend the execution of a process until one of its children terminates

- What is `EOF` / "end-of-file"?

---

## ✅ Requirements

### General



- Allowed editors: `vi`, `vim`, `emacs`

- All your files will be compiled on Ubuntu 20.04 LTS using `gcc`, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`

- All your files should end with a new line

- A `README.md` file, at the root of the folder of the project is mandatory

- Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/hs-hq/Betty/blob/master/betty-style.pl) and [betty-doc.pl](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl)

- Your shell should not have any memory leaks

- No more than 5 functions per file

- All your header files should be include guarded

- Use system calls only when you need to ([why?](https://www.quora.com/Why-are-system-calls-expensive-in-operating-systems))



### GitHub

**There should be one project repository per group. If you clone/fork/whatever a project repository with the same name before the second deadline, you risk a 0% score.**

---

## ⚙️ Setup

_No specific setup detected._

---

## 🧠 Quiz

_No quiz detected in the exported HTML._


---

## 🧩 Tasks

<details>
<summary>0. README, man, AUTHORS</summary>

**Files:**

- [`README.md`](https://github.com/Antgst/holbertonschool-simple_shell/blob/main/README.md)
- [`man_1_simple_shell`](https://github.com/Antgst/holbertonschool-simple_shell/blob/main/man_1_simple_shell)
- [`AUTHORS`](https://github.com/Antgst/holbertonschool-simple_shell/blob/main/AUTHORS)

**Repository:** `holbertonschool-simple_shell`

**Task details:**

```text
0. README, man, AUTHORS
Write a
README
Write a
man
for your shell.
You should have an
AUTHORS
file at the root of your repository, listing all individuals having contributed content to the repository. Format, see
Docker
Repo:
GitHub repository:
holbertonschool-simple_shell
File:
README.md, man_1_simple_shell, AUTHORS
Score of the task
58.5
/65
pts
90.0%
0
correction requests
QA Review
×
0. README, man, AUTHORS
Commit used:
User:
---
URL:
Click here
ID:
---
Author:
---
Subject:
---
Date:
---
×
Students who are done with "0. README, man, AUTHORS"
```

</details>

<details>
<summary>1. Betty would be proud</summary>

**Repository:** `holbertonschool-simple_shell`

**Task details:**

```text
1. Betty would be proud
Write a beautiful code that passes the Betty checks
Repo:
GitHub repository:
holbertonschool-simple_shell
Score of the task
10
/10
pts
100.0%
0
correction requests
My GitHub
Connect GitHub
Connect as:
Disconnect
Repository
Select a repository…
Folder (optional)
Run the correction
Get a sandbox
QA Review
×
1. Betty would be proud
Commit used:
User:
---
URL:
Click here
ID:
---
Author:
---
Subject:
---
Date:
---
×
Students who are done with "1. Betty would be proud"
×
Recommended Sandboxes
Loading...
```

</details>

<details>
<summary>2. Simple shell 0.1</summary>

**Repository:** `holbertonschool-simple_shell`

**Task details:**

```text
2. Simple shell 0.1
Write a UNIX command line interpreter.
Usage:
simple_shell
Your Shell should:
Display a prompt and wait for the user to type a command. A command line always ends with a new line.
The prompt is displayed again each time a command has been executed.
The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
The command lines are made only of one word. No arguments will be passed to programs.
If an executable cannot be found, print an error message and display the prompt again.
Handle errors.
You have to handle the "end of file" condition (
Ctrl+D
)
You don't have to:
use the
PATH
implement built-ins
handle special characters :
"
,
'
,
`
,
\
,
*
,
&
,
#
be able to move the cursor
handle commands with arguments
execve
will be the core part of your Shell, don't forget to pass the environ to it…
julien@ubuntu:~/shell$ ./shell
#cisfun$ ls
./shell: No such file or directory
#cisfun$ /bin/ls
barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell.c    stat.c
wait
env-environ.c
exec
fork    mypid   ppid
printenv
promptc  shell
stat
test_scripting.sh  wait.c
#cisfun$ ^[[D^[[D^[[D
./shell: No such file or directory
#cisfun$ ^[[C^[[C^[[C^[[C
./shell: No such file or directory
#cisfun$ exit
./shell: No such file or directory
#cisfun$ ^C
julien@ubuntu:~/shell$
echo
"/bin/ls"
| ./shell
barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell.c    stat.c
wait
env-environ.c
exec
fork    mypid   ppid
printenv
promptc  shell
stat
test_scripting.sh  wait.c
julien@ubuntu:~/shell$
Repo:
GitHub repository:
holbertonschool-simple_shell
Score of the task
7
/7
pts
100.0%
0
correction requests
My GitHub
Connect GitHub
Connect as:
Disconnect
Repository
Select a repository…
Folder (optional)
Run the correction
Get a sandbox
QA Review
×
2. Simple shell 0.1
Commit used:
User:
---
URL:
Click here
ID:
---
Author:
---
Subject:
---
Date:
---
×
Students who are done with "2. Simple shell 0.1"
×
Recommended Sandboxes
Loading...
```

</details>

<details>
<summary>3. Simple shell 0.2</summary>

**Repository:** `holbertonschool-simple_shell`

**Task details:**

```text
3. Simple shell 0.2
Simple shell 0.1 +
Handle command lines with arguments
Repo:
GitHub repository:
holbertonschool-simple_shell
Score of the task
3
/3
pts
100.0%
0
correction requests
My GitHub
Connect GitHub
Connect as:
Disconnect
Repository
Select a repository…
Folder (optional)
Run the correction
Get a sandbox
QA Review
×
3. Simple shell 0.2
Commit used:
User:
---
URL:
Click here
ID:
---
Author:
---
Subject:
---
Date:
---
×
Students who are done with "3. Simple shell 0.2"
×
Recommended Sandboxes
Loading...
```

</details>

<details>
<summary>4. Simple shell 0.3</summary>

**Repository:** `holbertonschool-simple_shell`

**Task details:**

```text
4. Simple shell 0.3
Simple shell 0.2 +
Handle the
PATH
fork
must not be called if the command doesn't exist
julien@ubuntu:~/shell$ ./shell_0.3
:) /bin/ls
barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell_0.3
stat
test_scripting.sh  wait.c
env-environ.c
exec
fork    mypid   ppid
printenv
promptc  shell     shell.c    stat.c
wait
:)
ls
barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell_0.3
stat
test_scripting.sh  wait.c
env-environ.c
exec
fork    mypid   ppid
printenv
promptc  shell     shell.c    stat.c
wait
:)
ls
-l /tmp
total 20
-rw------- 1 julien julien    0 Dec  5 12:09 config-err-aAMZrR
drwx------ 3 root   root   4096 Dec  5 12:09 systemd-private-062a0eca7f2a44349733e78cb4abdff4-colord.service-V7DUzr
drwx------ 3 root   root   4096 Dec  5 12:09 systemd-private-062a0eca7f2a44349733e78cb4abdff4-rtkit-daemon.service-ANGvoV
drwx------ 3 root   root   4096 Dec  5 12:07 systemd-private-062a0eca7f2a44349733e78cb4abdff4-systemd-timesyncd.service-CdXUtH
-rw-rw-r-- 1 julien julien    0 Dec  5 12:09 unity_support_test.0
:) ^C
julien@ubuntu:~/shell$
Repo:
GitHub repository:
holbertonschool-simple_shell
Score of the task
30
/30
pts
100.0%
0
correction requests
My GitHub
Connect GitHub
Connect as:
Disconnect
Repository
Select a repository…
Folder (optional)
Run the correction
Get a sandbox
QA Review
×
4. Simple shell 0.3
Commit used:
User:
---
URL:
Click here
ID:
---
Author:
---
Subject:
---
Date:
---
×
Students who are done with "4. Simple shell 0.3"
×
Recommended Sandboxes
Loading...
```

</details>

<details>
<summary>5. Simple shell 0.4</summary>

**Repository:** `holbertonschool-simple_shell`

**Task details:**

```text
5. Simple shell 0.4
Simple shell 0.3 +
Implement the
exit
built-in, that exits the shell
Usage:
exit
You don't have to handle any argument to the built-in
exit
Repo:
GitHub repository:
holbertonschool-simple_shell
Score of the task
2
/2
pts
100.0%
0
correction requests
My GitHub
Connect GitHub
Connect as:
Disconnect
Repository
Select a repository…
Folder (optional)
Run the correction
Get a sandbox
QA Review
×
5. Simple shell 0.4
Commit used:
User:
---
URL:
Click here
ID:
---
Author:
---
Subject:
---
Date:
---
×
Students who are done with "5. Simple shell 0.4"
×
Recommended Sandboxes
Loading...
```

</details>

<details>
<summary>6. Simple shell 1.0</summary>

**Repository:** `holbertonschool-simple_shell`

**Task details:**

```text
6. Simple shell 1.0
Simple shell 0.4 +
Implement the
env
built-in
, that prints the current environment
julien@ubuntu:~/shell$ ./simple_shell
$
env
USER=julien
LANGUAGE=en_US
SESSION=ubuntu
COMPIZ_CONFIG_PROFILE=ubuntu
SHLVL=1
HOME=/home/julien
C_IS=Fun_:)
DESKTOP_SESSION=ubuntu
LOGNAME=julien
TERM=xterm-256color
PATH=/home/julien/bin:/home/julien/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
DISPLAY=:0
$
exit
julien@ubuntu:~/shell$
Repo:
GitHub repository:
holbertonschool-simple_shell
Score of the task
3
/3
pts
100.0%
0
correction requests
My GitHub
Connect GitHub
Connect as:
Disconnect
Repository
Select a repository…
Folder (optional)
Run the correction
Get a sandbox
QA Review
×
6. Simple shell 1.0
Commit used:
User:
---
URL:
Click here
ID:
---
Author:
---
Subject:
---
Date:
---
×
Students who are done with "6. Simple shell 1.0"
×
Recommended Sandboxes
Loading...
```

</details>


---

## 🧪 Testing

Use the provided task examples and Holberton checker to validate the project.

---

## 👤 Author

Project from Holberton School.

README generated with Antoine's README Factory workflow.
