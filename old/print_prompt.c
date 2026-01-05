#include "shell.h"

/**
 * print_prompt - Print the asking prompt, here "#cisfun$ "
 * 
 * Return: Nothing
 */

void print_prompt(void)
{
    const char *prompt = "#cisfun$ ";
    write(STDOUT_FILENO, prompt, strlen(prompt));
}
