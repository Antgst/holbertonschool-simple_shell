#include <stdio.h>

/**
 * main - Prints the current process environment
 * @environ: global variable (provided by the system) its an array
 * of strings representing the process environment (NAME=VALUE)
 * 
 * Return: Always 0
 */

extern char **environ;

int main(void)
{
    char **env;

    for (env = environ; *env; env++)
    printf("%s\n", *env);

    return (0);
}
