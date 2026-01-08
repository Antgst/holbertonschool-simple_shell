#include "shell.h"

/**
 * exec - Executes a command in a child process.
 * @argv: Argument vector for the command.
 * @sname: Name of the program.
 * @line: Line number of the command.
 *
 * Return: Exit status of the command, or 1 on failure.
 */
int exec(char **argv, const char *sname, ssize_t line)
{
	char *fullpath = NULL;
	pid_t child_pid;
	int status, code;

	fullpath = pathmaker(argv);

	if (!fullpath)
	{
		fprintf(stderr, "%s: %lu: %s: not found\n",
			sname, line, argv[0]);
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

		fprintf(stderr, "%s: %lu: %s: exec failed\n",
			sname, line, argv[0]);
		free(fullpath);
		_exit(126);
	}
	if (waitpid(child_pid, &status, 0) == -1)
		return (1);

	free(fullpath);

	if (WIFEXITED(status))
		code = WEXITSTATUS(status);
	else
		code = 1;

	return (code);
}
