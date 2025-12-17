#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
char *match_var(const char *s1, char *s2);
char *_getenv(const char *name);
extern char **environ;

int main(void)
{
	char *path;

	path = _getenv("PATH");

	if (path == NULL)
	{
		printf("not found\n");
		return (1);
	}

	printf("%s\n", path);

	return (0);
}


char *_getenv(const char *name)
{
	unsigned int i;
	char *env = NULL;


	for (i = 0; environ[i] != NULL; i++)
	{
		env = match_var(name, environ[i]);

		if (env != NULL)
			return (env);
	}

	return (NULL);
}

/**
 * match_var - compare the ascii value of two strings
 * @s1: string 1 to compare
 * @s2: string 2 to compare
 * @env: pointer to the env we search
 * Return: int
 */
char *match_var(const char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			break;
		i++;
	}

	if (s1[i] == '\0' && s2[i] == '=')
	{
		return (&s2[i + 1]);
	}

	return (NULL);
}
