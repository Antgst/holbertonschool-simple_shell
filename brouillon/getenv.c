#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char *match_var(const char *s1, char *s2);
char *_getenv(const char *name);
void printpath(void);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);

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

	printpath();

	return (0);
}

void printpath(void)
{
	char *truepath, *path = NULL;
	char *splitpath = NULL;

	truepath = _getenv("PATH");
	path = malloc(_strlen(truepath + 1));
	path = _strcpy(path, truepath);

	splitpath = strtok(path, ":");

	while (splitpath != NULL)
	{
		printf("%s\n", splitpath);
		splitpath = strtok(NULL, ":");
	}
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


char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int _strlen(char *s)
{
	char *p = s;
	int x;

	x = 0;
	while (*p != '\0')
	{
		x++;
		p++;
	}
	return (x);
}
