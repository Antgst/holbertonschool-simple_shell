#include <string.h>
#include <stdio.h>

/**
 * main - Splits a string into words 
 * using strtok and prints each token
 *
 * Return: Always 0 on success
 */

int main(void)
{
	char str[] = "Split this string";
	char *split;

	if (str[0] != '\0')
	split = strtok(str, " ");

	while (split != NULL)
	{
		printf("%s\n", split);
		split = strtok(NULL, " ");
	}

	return (0);

}
