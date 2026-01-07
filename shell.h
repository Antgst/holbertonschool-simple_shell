#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strdup(char *str);
char *_strchr(char *s, char c);

int exec(char **argv, const char *shell_name, ssize_t line);
char **tokenize_line(char *line);
char *pathmaker(char **av);
int use_line(char *line, ssize_t line_no, char **av, int last_status);

char *_getenv(const char *name);
int print_env(void);

#endif
