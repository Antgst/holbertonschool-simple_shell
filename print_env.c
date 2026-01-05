#include "shell.h"

/**
 * print_env - Prints the environment variables.
 *
 * Return: 0 on success.
 */
int print_env(void)
{
	unsigned int i;

	i = 0;
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}
