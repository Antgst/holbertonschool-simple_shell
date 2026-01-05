#include "shell.h"

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
