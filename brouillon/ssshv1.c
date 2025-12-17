#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int _strcmp(char *s1, char *s2);


/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
	char *line = NULL;
	unsigned long int buffer = 0;
	ssize_t size;
	unsigned int i;
	pid_t child_pid;
	int status;
	char *argv[2];

	while (line != "exit\n")
	{
		printf("$ ");
		size = getline(&line, &buffer, stdin);

		if (line[size - 1] == '\n')
			line[size - 1] = '\0';

		if (_strcmp(line, "exit\n") == 0 || size == -1)
		{
			putchar('\n');
			free(line);
			return (0);
		}

		child_pid = fork();

		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}

		if (child_pid == 0)
		{
			if (execve(line, argv, NULL) == -1)
			{
				perror("Error:");
			}
		}
		else
		{
			wait(&status);
		}
	}
	free(line);
	return (0);
}

/**
 * _strcmp - compare the ascii value of two strings
 * @s1: string 1 to compare
 * @s2: string 2 to compare
 * Return: int
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			break;
		i++;
	}

	return (s1[i] - s2[i]);
}
