#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern char **environ;

/**
 * _getenv - Gets the value of an environment variable
 * @name: Name of the environment to search (Ex: "PATH")
 * 
 * Return: A pointer to the value part of the "NAME=VALUE" string,
 * or NULL if @name is NULL/EMPTY or if the variable is not found
 */

char *_getenv(const char *name)
{
    size_t len;
    int i;

    if (name == NULL || *name == '\0')
        return (NULL);

    len = strlen(name);

    for (i = 0; environ[i]; i++)
    {
        if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
            return (environ[i] + (len + 1));
    }

    return (NULL);
}

/**
 * print_path_directories - Prints each directories listed in the path environment variable
 * 
 * Return: Void
 */

void print_path_directories(void)
{
    char *path = _getenv("PATH");
    char *copy;
    char *dir;

    if (path == NULL)
        return;

    copy = strdup(path);
    if (copy == NULL)
        return;
    
    for (dir = strtok(copy, ":"); dir; dir = strtok(NULL, ":"))
        printf("%s\n", dir);
    
    free(copy);
}

/**
 * main - Entry point
 * 
 * Return: Always 0
 */

int main(void)
{
    print_path_directories();
    return (0);
}
