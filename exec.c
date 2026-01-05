#include "shell.h"

/**
 * exec - execute a command using execve
 * @argv: array of arguments, with argv[0] as the command
 *
 * Return: 0 on success, 1 on failure
 */
int exec(char **argv)
{
	unsigned int i;

	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}

	if (child_pid == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			perror("Error:");
		}
	}
	else
	{
		wait(&status);
	}

	return (0);
}

