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
	int status;
	pid_t pid;

	while(1)
	{
		printf("#cisfun$ ");
		read = getline(&line, &len, stdin);
		
		if (read == -1)
		{
			printf("\n");
			break;
		}

		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		pid = fork();

		if (pid == -1)
		{
			perror("Error:");
			continue;
		}

		if (pid == 0)
		{
			char *argv[] = {line, NULL};
			execve(argv[0], argv, NULL);
			perror("Execve:");
			return (0);
		}

		else
		{
			wait(&status);
		}
	}
	free(line);
	return(0);
}
