#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * read_line - Prints "$ ", reads a line from stdin and prints it back
 * 
 * Return: 0 on success or on EOF, and -1 on failure
 */

int read_line(void);
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t number_read;

	while (1)
	{
		printf("$ ");
		fflush(stdout);

		number_read = getline(&line, &len, stdin);
		if (number_read == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				break;
			}
			free(line);
			return (-1);
		}
		
		printf("%s", line);
	}

	free(line);
	return (0);
}

/**
 * main - Entry point
 *
 * Return: 0 on success, -1 on failure
 */

int main(void)
{
	return (read_line());
}
