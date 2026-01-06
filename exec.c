#include "shell.h"

/**
 * exec - Executes a command in a child process
 * @argv: Argument vector for the command
 * @sname: Name of the shell program (argv[0])
 * @line: Command line number (for error messages)
 *
 * Return: Exit status for the executed command (or error status)
 */
int exec(char **argv, const char *sname, unsigned long line)
{
	char *fullpath = NULL;
	pid_t child_pid;
	int status;

	fullpath = pathmaker(argv);
	if (fullpath == NULL)
	{
		fprintf(stderr, "%s: %lu: %s: not found\n", sname, line, argv[0]);
		return (127);
	}

	child_pid = fork();
	if (child_pid == -1)
	{
		perror(sname);
		free(fullpath);
		return (1);
	}

	if (child_pid == 0)
	{
		execve(fullpath, argv, environ);

		fprintf(stderr, "%s: %lu: %s: %s\n",
			sname, line, argv[0], _strerror(errno));

		free(fullpath);

		if (errno == EACCES || errno == EISDIR)
			_exit(126);

		_exit(127);
	}

	if (waitpid(child_pid, &status, 0) == -1)
	{
		perror(sname);
		free(fullpath);
		return (1);
	}

	free(fullpath);

	if (WIFEXITED(status))
		return (WEXITSTATUS(status));

	if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));

	return (1);
}
