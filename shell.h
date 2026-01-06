#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

extern char **environ;

int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);

int exec(char **argv, const char *shell_name, unsigned long line);
char **tokenize_line(char *line);
char *pathmaker(char **av);

char *_getenv(const char *name);
int print_env(void);

#endif
