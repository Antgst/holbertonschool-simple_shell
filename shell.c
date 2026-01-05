#include "shell.h"

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
	char *line = NULL;
	unsigned long int buffer = 0;
	ssize_t size;
	unsigned int i;
	pid_t child_pid;
	int status;
	char **argv;

	while (line != "exit\n")
	{
		printf("$ ");
		size = getline(&line, &buffer, stdin);

		if (line[size - 1] == '\n')
			line[size - 1] = '\0';

		if (_strcmp(line, "exit\n") == 0 || size == -1)
		{
			putchar('\n');
			free(line);
			return (0);
		}

		argv = tokenize_line(line);
		exec(argv);
	}
	free(line);
	return (0);
}
