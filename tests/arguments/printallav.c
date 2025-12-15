#include <stdio.h>
#include <unistd.h>

/**
 * main - check the code
 * @ac: the number of arguments
 * @av: the array where arguments are stored
 * 
 * Return: 0
 */

int main(int ac, char **av)
{
	unsigned int i;

	for (i = 0; av[i] != NULL; i++)
	{
		printf("%s\n", av[i]);
	}
	return (0);
}