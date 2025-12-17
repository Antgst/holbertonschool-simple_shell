#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char *make_path(char *path, char *file);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);

/**
 * main - stat example
 * @ac: argc
 * @av: argv
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	unsigned int i, check;
	struct stat st;
	char *path = getenv("PATH");
	char *spath, *path_copy;
	char *fullpath;


	if (ac < 2)
	{
		printf("Usage: %s path_to_file\n", av[0]);
		return (1);
	}

	i = 1;
	while (av[i])
	{
		path_copy = malloc(_strlen(path) + 1);
		if (!path_copy)
			return (1);
		_strcpy(path_copy, path);

		spath = strtok(path_copy, ":");

		check = 0;
		while (spath != NULL)
		{
			fullpath = make_path(spath, av[i]);
			if (stat(fullpath, &st) == 0)
			{
				printf("%s:", fullpath);
				printf(" FOUND\n");
				check = 1;
				free(fullpath);
				break;
			}
			free(fullpath);
			spath = strtok(NULL, ":");
		}
		if (check == 0)
			printf("%s: NOT FOUND\n", av[i]);
		free(path_copy);
		i++;
	}

	return (0);
}

char *make_path(char *path, char *file)
{
	char *fullpath;
	int i = 0, y;
	int len;

	len = _strlen(path) + 1 + _strlen(file) + 1;
	fullpath = malloc(len);
	if (!fullpath)
		return (NULL);

	while (path[i] != '\0')
	{
		fullpath[i] = path[i];
		i++;
	}
	fullpath[i] = '/';

	y = i + 1;
	i = 0;
	while (file[i] != '\0')
	{
		fullpath[y] = file[i];
		i++;
		y++;
	}
	fullpath[y] = '\0';
	return (fullpath);
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
