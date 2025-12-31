#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>     /* for getline, file */
#include <stdlib.h>    /* for malloc, free */
#include <unistd.h>    /* for fork, execve, isatty */
#include <string.h>    /* for strlen, strtok, strcmp */
#include <sys/wait.h>  /* for wait, pid */
#include <errno.h>     /* for errno */
#include <sys/stat.h>  /* for later */
#include <signal.h>    /* for later */

extern char **environ;

int stdin_isatty(void);
void print_prompt(void);
ssize_t read_line(char **line, size_t *bufcap);
void remove_newline(char *line);
int is_blank_line(const char *line);
int execute_simple(const char *cmd, const char *prog, unsigned long line_no);
void print_not_found(const char *prog, unsigned long line_no, const char *cmd);

#endif /*SHELL_H*/