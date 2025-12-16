#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

/**
 * main - Create a super simple shell test
 * 
 * 
 * Return:
 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

		printf("supersimpleshell$ ");
		read = getline(&line, &len, stdin);
		
		if (read == -1)
		{
			free(line);
			return (0);
		}
}
