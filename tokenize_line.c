#include "shell.h"

/**
 * tokenize_line - Split a command line into an argv array
 * @line: Input line to tokenize
 *
 * Return: NULL-terminated argv array, or NULL if it failed
 */

char **tokenize_line(char *line)
{
    char *token;
    size_t argcount = 0;
    char **argv;
    char copy[1024];
    size_t idx = 0;

    if (line == NULL)
        return (NULL);

    _strcpy(copy, line);

    if (copy == NULL)
        return (NULL);

    token = strtok(copy, " \t");

    while (token != NULL)
    {
        argcount++;
        token = strtok(NULL, " \t");
    }

    if (argcount == 0)
        return (NULL);

    argv = malloc(sizeof(char *) * (argcount + 1));

    if (argv == NULL)
        return (NULL);

    token = strtok(line, " \t");

    while (token != NULL)
    {
        argv[idx] = token;
        idx++;
        token = strtok(NULL, " \t");
    }

    argv[idx] = NULL;

    return (argv);
}
