#include "shell.h"

/**
 * get_env_value - Get the value of an environment variable from environ
 * @name: Environment variable name (example: "PATH")
 * 
 * Return: Pointer to the value inside environ (do not modify), or NULL if it is not found
 */

char *get_env_value(const char *name)
{
    size_t len;
    int i;

    if (name == NULL || name[0] == '\0')
        return (NULL);

    len = strlen(name);

    for (i = 0; environ[i] != NULL; i++)
    {
        if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
            return (environ[i] + len + 1);
    }

    return (NULL);
}
