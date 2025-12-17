#include <stdio.h>
#include <unistd.h>

extern char ** environ;

/**
 * main - Compare the env argument and the global environ variable
 * @ac: The number of arguments
 * @av: The array of the arguments
 * @env: Environment variables passes to main
 * 
 * Return: Always 0
 */

int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;

    printf("Adress of env : %p\n", (void*)env);
    printf("Adress of environ : %p\n", (void*)environ);

    printf("env[0] : %s\n", env[0]);
    printf("environ[0] : %s\n", environ[0]);

    return (0);
}
