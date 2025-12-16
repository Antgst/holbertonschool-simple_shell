#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - Forks 5 times to execute /bin/ls -l /tmp/ in a child process
 * and waits for each child to finish
 *
 * Return: O on success, 1 on failure 
 */

int main(void)
{
	int i;
	char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};

	pid_t child_pid;
	int status;

	for (i = 0; i < 5; i++)
	{
		child_pid = fork ();

		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}

		if (child_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
			}
		}

		wait(&status);
	}

	return (0);
}
