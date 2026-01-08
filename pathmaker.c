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
	char *path = _getenv("PATH");
	char *spath, *path_copy;
	char *fullpath = NULL;

	if (!av || !av[0])
		return (NULL);

	if (_strchr(av[0], '/'))
	{
		if (access(av[0], F_OK) == -1)
			return (NULL);
		return (_strdup(av[0]));
	}

	if (path == NULL)
		return (NULL);

	path_copy = _strdup(path);
	if (path_copy == NULL)
		return (NULL);

	spath = strtok(path_copy, ":");

	while (spath != NULL)
	{
		if (spath[0] == '\0')
			spath = ".";

		fullpath = make_path(spath, av[0]);
		if (!fullpath)
		{
			free(path_copy);
			return (NULL);
		}

		if (stat(fullpath, &st) == 0)
		{
			free(path_copy);
			return (fullpath);
		}

		free(fullpath);
		fullpath = NULL;
		spath = strtok(NULL, ":");
	}
	free(path_copy);

	return (NULL);
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
