#include <stdio.h>
#include <string.h>

extern char **environ;

/**
 * _getenv: Get the value of the environment variable
 * @name: name of the variable (Ex: "PATH")
 *
 * Return: A pointer to the value, or NULL if its not found
 */

char *_getenv(const char *name)
{
    size_t len;
    int i;

    if (name == NULL || *name == '\0')
        return (NULL);
    
    len = strlen(name);

    for (i = 0; environ[i] != NULL; i++)
    {
        if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
            return (environ[i] + (len + 1));
    }

    return (NULL);
}

/**
 * main - Check the code
 * 
 * Return: Always 0
 */

int main(void)
{
    const char *keys[] = {"PATH", "HOME", NULL};
    int i;
    char *value;

    for (i = 0; keys[i] != NULL; i++)
    {
        value = _getenv(keys[i]);
        if (value)
            printf("%s=%s\n", keys[i], value);
            printf("%s not found\n", keys[i]);
    }

    return (0);
}
