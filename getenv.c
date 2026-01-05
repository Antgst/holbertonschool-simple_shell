#include "shell.h"

char *match_var(const char *s1, char *s2);

/**
 * _getenv - Gets the value of an environment variable.
 * @name: Name of the environment variable.
 *
 * Return: Pointer to the value, or NULL if not found.
 */
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
 * match_var - Matches an environment variable name with a string.
 * @s1: Variable name to match.
 * @s2: Environment string in the form NAME=value.
 *
 * Return: Pointer to the value if matched, or NULL otherwise.
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
