#include "shell.h"

/**
 * resolve_path - Resolve a command name to an executable path
 * @cmd: Command name (example: "ls") or a path (example: "/bin/ls")
 * 
 * Return: Newly allocated string containing the resolved path, or NULL if not found
 */

char *resolve_path(const char *cmd)
{
    const char *path;
    char *path_copy;
    char *path_dir;

    if (cmd == NULL || cmd[0] == '\0')
        return (NULL);

    if (strchr(cmd, '/') != NULL)
    {
        if (access(cmd, X_OK) == 0)
            return (strdup(cmd));
        return (NULL);
    }

    path = get_env_value("PATH");
    if (path == NULL || path[0] == '\0')
        return (NULL);

    path_copy = strdup(path);
    if (path_copy == NULL)
        return (NULL);

    path_dir = strtok(path_copy, ":");

    while (path_dir != NULL)
    {
        size_t size;
        char *candidate_path;

        size = strlen(path_dir) + 1 + strlen(cmd) + 1;
        candidate_path = malloc(size);
        if (candidate_path == NULL)
        {
            free(path_copy);
            return (NULL);
        }

        sprintf(candidate_path, "%s/%s", path_dir, cmd);
        if (access(candidate_path, X_OK) == 0)
        {
            free(path_copy);
            return (candidate_path);
        }

        free(candidate_path);
        path_dir = strtok(NULL, ":");
    }

    free(path_copy);
    return (NULL);
}
