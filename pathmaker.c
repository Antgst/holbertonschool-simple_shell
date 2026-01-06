#include "shell.h"

char *make_path(char *path, char *file);

/**
 * pathmaker - Build the full path for a command using PATH
 * @av: Argument vector (av[0] is the command name)
 *
 * Return: Newly allocated full path, or NULL if not found
 */
char *pathmaker(char **av)
{
	struct stat st;
	char *path, *path_copy, *start, *end;
	char *fullpath;

	if (av == NULL || av[0] == NULL)
		return (NULL);

	/* If command contains '/', do not search PATH (like /bin/sh). */
	if (strchr(av[0], '/') != NULL)
	{
		if (stat(av[0], &st) == 0)
			return (_strdup(av[0]));
		return (NULL);
	}

	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);

	path_copy = _strdup(path);
	if (path_copy == NULL)
		return (NULL);

	start = path_copy;
	while (start != NULL)
	{
		char *dir;

		end = strchr(start, ':');
		if (end != NULL)
			*end = '\0';

		/* Empty entry means current directory. */
		dir = (*start == '\0') ? "." : start;

		fullpath = make_path(dir, av[0]);
		if (fullpath == NULL)
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

		if (end == NULL)
			break;

		start = end + 1;
	}

	free(path_copy);
	return (NULL);
}

/**
 * make_path - Concatenate a directory and a file into a full path
 * @path: Directory path
 * @file: File name
 *
 * Return: Newly allocated full path, or NULL on failure
 */
char *make_path(char *path, char *file)
{
	char *fullpath;
	int i = 0, y;
	int len;

	len = _strlen(path) + 1 + _strlen(file) + 1;
	fullpath = malloc(len);
	if (fullpath == NULL)
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
