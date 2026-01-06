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
	char *copy, *start, *end;
	char *fullpath = NULL;
	int saw_eacces = 0;
	char saved;

	if (!av || !av[0])
		return (NULL);

	/* Si la commande contient '/', on ne cherche PAS dans PATH */
	if (strchr(av[0], '/') != NULL)
	{
		if (stat(av[0], &st) == 0)
			return (_strdup(av[0]));
		return (NULL);
	}

	if (path == NULL)
		return (NULL);

	copy = _strdup(path);
	if (copy == NULL)
		return (NULL);

	start = copy;

	while (1)
	{
		end = start;
		while (*end && *end != ':')
			end++;

		saved = *end;      /* ':' ou '\0' */
		*end = '\0';       /* on isole le token */

		/* token vide => "." */
		if (*start == '\0')
			fullpath = make_path(".", av[0]);
		else
			fullpath = make_path(start, av[0]);

		*end = saved;      /* on restaure */

		if (fullpath == NULL)
		{
			free(copy);
			return (NULL);
		}

		if (stat(fullpath, &st) == 0)
		{
			free(copy);
			return (fullpath);
		}

		if (errno == EACCES)
			saw_eacces = 1;

		free(fullpath);
		fullpath = NULL;

		if (saved == '\0')
			break;

		start = end + 1;
	}

	free(copy);

	if (saw_eacces)
		errno = EACCES;

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
