#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * free_split - Frees a NULL-terminated array of strings
 * @words: Array to free
 *
 * Return: Nothing
 */

void free_split(char **words)
{
	size_t i;

	if (words == NULL)
		return;
	
	for (i = 0; words[i] != NULL; i++)
		free(words[i]);
	
	free(words);
}

/**
 * split - Splits a string into words (NULL-terminated array)
 * @str: Input string (not modified)
 * @delim: Delimiters (If NULL, defaults to " \t\n")
 * 
 * Return: Pointer to the array of words, or NULL on failure / no tokens
 */

char **split(const char *str, const char *delim)
{
	char *tmp;
	char *token;
	size_t count = 0;
	size_t i = 0;
	char **words;

	if (str == NULL)
		return (NULL);

	if (delim == NULL)
		delim = " \t\n";

	/* Pass 1: Count tokens */
	tmp = malloc(strlen(str) + 1);
	if (tmp == NULL)
		return (NULL);
	strcpy(tmp, str);

	token = strtok(tmp, delim);
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, delim);
	}
	free(tmp);

	if (count == 0)
		return (NULL);
	
	words = malloc(sizeof(char *) * (count + 1));
	if (words == NULL)
		return (NULL);

	/* Pass 2: Fill words */
	tmp = malloc(strlen(str) + 1);
	if (tmp == NULL)
	{
		free(words);
		return (NULL);
	}
	strcpy(tmp, str);

	token = strtok(tmp, delim);
	while (token != NULL)
	{
		words[i] = malloc(strlen(token) + 1);
		if (words[i] == NULL)
		{
			free(tmp);
			words[i] = NULL;
			free_split(words);
			return (NULL);
		}
		strcpy(words[i], token);
		i++;
		token = strtok(NULL, delim);
	}
	words[i] = NULL;

	free(tmp);
	return (words);
}

/**
 * main - Entry point
 * 
 * Return: Always 0
 */

int main(void)
{
	char **av;
	size_t i;
	const char *line = "  ls   -l\t/tmp\n";

	av = split(line, " \t\n");
	if (av == NULL)
	{
		printf("split returned NULL\n");
		return (0);
	}

	for (i = 0; av[i] != NULL; i++)
		printf("av[%lu] = [%s]\n", (unsigned long)i, av[i]);

	free_split(av);
	return (0);
}
