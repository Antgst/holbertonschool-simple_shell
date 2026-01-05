#include "shell.h"

/**
 * main - PID
 * @ac: Argument count.
 * @av: Argument vector.
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	char *line = NULL;
	unsigned long int buffer = 0;
	ssize_t size;
	char **argv;
	ssize_t line_no = 0;

	(void)ac;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");

		size = getline(&line, &buffer, stdin);
		line_no++;
		if (size == -1)
		{
			printf("\n");
			free(line);
			return (0);
		}

		if (line[size - 1] == '\n')
			line[size - 1] = '\0';

		if (_strcmp(line, "exit") == 0)
		{
			free(line);
			return (2);
		}
		if (_strcmp(line, "env") == 0)
		{
			print_env();
			continue;
		}
		argv = tokenize_line(line);
		if (argv != NULL)
			exec(argv, av[0], line_no);
	}
}
