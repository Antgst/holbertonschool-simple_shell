#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
	char *line = NULL;
	unsigned long int buffer = 0;

	while (line != "exit\n")
	{
		printf("$ ");
		getline(&line, &buffer, stdin);
		if (line == "exit")
		{
			printf("exited");
			free(line);
			return (0);
		}

		printf("line : %sbuffer : %li\n", line, buffer);
	}
	free(line);
	return (0);
}
