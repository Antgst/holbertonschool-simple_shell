#include "shell.h"

/**
 * execute_simple - Fork, execute and wait for a single-word command
 * @cmd: path to the command to execute
 * @prog: name of the shell argv[0] for perror
 * @line_no: Number of line/command
 * 
 * Return: 0 if success on parent, or 1 if it failed
 */

int execute_simple(const char *cmd, const char *prog, unsigned long line_no)
{
    (void)line_no;
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1)
    {
        perror("fork");
        return (1);
    }

    if (pid == 0)
    {
        char *argv_exec[2];
        argv_exec[0] = (char *)cmd;
        argv_exec[1] = NULL;

        execve(cmd, argv_exec, environ);

        perror(prog);
        exit(EXIT_FAILURE);
    }

    if (wait(&status) == -1)
    {
        perror("wait");
        return (1);
    }
        
    return (0);
}
