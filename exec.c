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
	int status, code;

	fullpath = pathmaker(argv);

	if (!fullpath)
	{
		dprintf(STDERR_FILENO, "%s: %lu: %s: %s\n",
			sname, line, argv[0], _strerror(errno));
		return (127);

	}
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		free(fullpath);
		return (1);
	}

	if (child_pid == 0)
	{
		execve(fullpath, argv, environ);

		dprintf(STDERR_FILENO, "%s: %lu: %s: %s\n",
			sname, line, argv[0], _strerror(errno));
		free(fullpath);
		_exit(126);
	}

	free(fullpath);

	wait(&status);
	if (WIFEXITED(status))
		code = WEXITSTATUS(status);

	return (code);
}
