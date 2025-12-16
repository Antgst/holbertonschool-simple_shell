#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * read_line - Prints "$ ", reads a line from stdin and prints it back
 * 
 * Return: 0 on success or on EOF, and -1 on failure
 */

int read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t number_read;

	printf("$ ");
	number_read = getline(&line, &len, stdin);
	
	if (number_read == -1)
	{
		free(line);
		return (0);
	}
	
	printf("%s", line);
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
