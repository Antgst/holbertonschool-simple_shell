#include "shell.h"

/**
 * is_blank_line - Check if the line is empty or contains only character like '', ' ', '\t'
 * @line: Pointer to the line to be checked
 * 
 * Return: 1 if the line is empty or contains ONLY spaces or tabs, 0 otherwise
 */

int is_blank_line(const char *line)
{
    if (line == NULL)
    return (0);

    while (*line != '\0')
    {
        if (*line != ' ' && *line != '\t')
            return (0);
        line++;
    }

    return (1);
}
