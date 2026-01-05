#include "shell.h"

/**
 * _strdup - Returns a pointer to a newly allocated space in memory
 *            containing a copy of a given string.
 * @str: String to duplicate.
 *
 * Return: Pointer to duplicated string, or NULL if str is NULL
 *         or if memory allocation fails.
 */
char *_strdup(char *str)
{
	char *array;
	unsigned int i, size;

	i = 0;
	size = 0;

	if (str == NULL)
	{
		return (NULL);
	}

	while (str[size] != '\0')
	{
		size++;
	}

	array = malloc(size + 1);
	if (array == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < size; i++)
	{
		array[i] = str[i];
	}
	array[size] = '\0';

	return (array);
}
