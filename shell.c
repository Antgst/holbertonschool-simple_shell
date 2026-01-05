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
	char *argv[2];

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

		child_pid = fork();

		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}

		if (child_pid == 0)
		{
			if (execve(line, argv, NULL) == -1)
			{
				perror("Error:");
			}
		}
		else
		{
			wait(&status);
		}
	}
	free(line);
	return (0);
}
