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

	while (1)
	{
		printf("$ ");
		size = getline(&line, &buffer, stdin);

		if (line[size - 1] == '\n')
			line[size - 1] = '\0';

		if (_strcmp(line, "exit") == 0 || size == -1)
		{
			free(line);
			return (0);
		}

		if (_strcmp(line, "env") == 0 || size == -1)
		{
			print_env();
			continue;
		}

		argv = tokenize_line(line);
		argv[0] = pathmaker(argv);
		exec(argv);
	}
	free(line);
	return (0);
}
