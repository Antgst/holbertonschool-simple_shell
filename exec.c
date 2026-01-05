#include "shell.h"

/**
 * exec - execute a command using execve
 * @argv: array of arguments, with argv[0] as the command
 *
 * Return: 0 on success, 1 on failure
 */
int exec(char **argv, const char *shell_name, ssize_t line)
{
	char *fullpath = NULL;
	pid_t child_pid;
	int status;

	fullpath = pathmaker(argv);
	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}

	if (child_pid == 0)
	{
		if (execve(fullpath, argv, environ) == -1)
		{
			dprintf(STDERR_FILENO, "%s: %lu: %s: not found\n", shell_name, line, argv[0]);
			exit(127);
		}
	}
	else
	{
		wait(&status);
	}

	return (0);
}
