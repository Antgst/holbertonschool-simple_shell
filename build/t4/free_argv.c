#include "shell.h"

/**
 * free_argv - Free an argv array allocated by tokenize_line
 * @argv: NULL-terminated argv array to free
 * 
 * Return: Nothing
 */

void free_argv(char **argv)
{
    if (argv == NULL)
        return;
    
    free(argv);
}
