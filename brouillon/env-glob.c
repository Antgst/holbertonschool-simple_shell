#include <stdio.h>

extern char **environ;

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{

	printf("%p\n", (void *)env);
	printf("%p\n", (void *)environ);

	return (0);
}
