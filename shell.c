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
	int last_status = 0;
	(void)ac;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		size = getline(&line, &buffer, stdin);
		if (size == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			free(line);
			return (last_status);
		}
		if (line[size - 1] == '\n')
			line[size - 1] = '\0';

		if (_strcmp(line, "exit") == 0)
		{
			free(line);
			return (last_status);
		}
		if (_strcmp(line, "env") == 0)
		{
			print_env();
			continue;
		}
		line_no++;
		argv = tokenize_line(line);
		if (argv != NULL)
		{
		last_status = exec(argv, av[0], line_no);
			free(argv);
		}
	}
}
