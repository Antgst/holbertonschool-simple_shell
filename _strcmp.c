#include "shell.h"

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
