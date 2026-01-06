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
		line_no++;
		if (line[size - 1] == '\n')
			line[size - 1] = '\0';

		argv = tokenize_line(line);
		if (argv != NULL)
		{
			if (_strcmp(argv[0], "exit") == 0)
			{
				free(argv);
				free(line);
				exit(last_status);
			}
			if (_strcmp(argv[0], "env") == 0)
			{
				print_env();
				free(argv);
				continue;
			}
			last_status = exec(argv, av[0], line_no);
			free(argv);
		}
	}
}
