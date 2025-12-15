#include <stdio.h>

/**
 * main - Prints all command line arguments
 * @ac: the number of arguments
 * @av: the array where arguments are stored
 *
 * Return: 0
 */

int main(int ac, char **av)
{
	int i;
	(void)ac;

	for (i = 0; av[i] != NULL; i++)
	{
		printf("%s\n", av[i]);
	}
	return (0);
}
