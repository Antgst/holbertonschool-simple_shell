#include "shell.h"

/**
 * remove_newline - Remove the '\n' from the line
 * @line: The buffer containing the line to be clean
 *  
 * Return: Nothing
 */

void remove_newline(char *line)
{
    size_t len;

    if (line == NULL)
        return;

    len = strlen(line);
    if (len == 0)
        return;

    if (line[len - 1] == '\n')
        line[len - 1] = '\0';
}
