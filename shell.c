#include "shell.h"

/**
 * main - Entry point for the simple shell
 * @ac: Argument count (unused)
 * @av: Argument vector (argv[0] is used for error messages)
 *
 * Return: Exit status of the last executed command
 */
int main(int ac, char **av)
{
	char *line = NULL;
	size_t buffer = 0;
	ssize_t nread;
	char **argv;
	unsigned long line_no = 0;
	int last_status = 0;

	(void)ac;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("($) ");

		nread = getline(&line, &buffer, stdin);
		if (nread == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			free(line);
			return (last_status);
		}

		line_no++;

		if (nread > 0 && line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		argv = tokenize_line(line);
		if (argv == NULL)
			continue;

		if (_strcmp(argv[0], "exit") == 0)
		{
			free(argv);
			free(line);
			return (last_status);
		}

		if (_strcmp(argv[0], "env") == 0)
		{
			print_env();
			last_status = 0;
			free(argv);
			continue;
		}

		last_status = exec(argv, av[0], line_no);
		free(argv);
	}
}
