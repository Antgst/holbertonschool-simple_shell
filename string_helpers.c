#include "shell.h"

/**
 * _strchr - locates a character in a string
 * @s: the string to search
 * @c: the character to search
 * Return: a pointer to the first occurrence of the character c
 *		in the string s, or NULL if the character is not found
 */
char *_strchr(char *s, char c)
{
	unsigned int i = 0;

	while (1)
	{
		if (s[i] == c)
			return (s + i);
		else if (s[i] == '\0')
			break;
		i++;
	}
	return (NULL);
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

/**
 * _strcpy - copies a string into a destination buffer
 * @dest: buffer to copy into
 * @src: string to copy
 * Return: pointer to dest
 */
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

/**
 * _strlen - returns the length of a string
 * @s: string to measure
 * Return: number of characters in the string
 */
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
