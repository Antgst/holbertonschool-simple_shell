#include "shell.h"

/**
 * stdin_isatty - Test if the shell is a interactive terminal or not 
 * 
 * Return: 1 if stdin is a interactive terminal, otherwise 0
 */

int stdin_isatty(void)
{
    if (isatty(STDIN_FILENO))
        return (1);
        
    return (0);
}
