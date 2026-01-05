#include "shell.h"

char *make_path(char *path, char *file);

/**
 * pathmaker - Searches for files in directories listed in the PATH environment
 * @av: Array of arguments containing file names to search.
 *
 * Return: 0 on success, 1 on failure.
 */

char *pathmaker(char **av)
{
	struct stat st;
	char *path = getenv("PATH");
	char *spath, *path_copy;
	char *fullpath;

	path_copy = malloc(_strlen(path) + 1);
	if (!path_copy)
		return (av[0]);
	_strcpy(path_copy, path);

	spath = strtok(path_copy, ":");

	if (stat(av[0], &st) != 0)
	{
		while (spath != NULL)
		{
			fullpath = make_path(spath, av[0]);

			if (stat(fullpath, &st) == 0)
				break;

			spath = strtok(NULL, ":");
		}
		free(path_copy);
		return (fullpath);
	}
	else
	{
		return (av[0]);
	}
}

/**
 * make_path - concatenate path and file into a full path
 *
 * @path: path to directory
 * @file: name of file
 *
 * Return: pointer to full path, or NULL if error
 */
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
