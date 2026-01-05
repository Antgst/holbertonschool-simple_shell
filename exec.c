#include "shell.h"

/**
 * exec - Executes a command in a child process.
 * @argv: Argument vector for the command.
 * @sname: Name of the program.
 * @line: Line number of the command.
 *
 * Return: 0 on success, 1 on failure.
 */
int exec(char **argv, const char *sname, ssize_t line)
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
			dprintf(STDERR_FILENO, "%s: %lu: %s: not found\n", sname, line, argv[0]);
			exit(127);
		}
	}
	else
	{
		wait(&status);
	}

	return (0);
}
