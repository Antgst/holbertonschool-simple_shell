#include "shell.h"

/**
 * execute_args - Fork, execute and wait for a command with arguments
 * @line: Modifiable line containing the command and its arguments
 * @prog: Program name (argv[0]) used for perror on exec failure
 * @line_no: Line/command number
 * 
 * Return: 0 on success, 1 if it failed (fork/wait)
 */

int execute_args(char *line, const char *prog, unsigned long line_no)
{
    (void)line_no;
    char **argv;
    pid_t pid;
    int status;

    argv = tokenize_line(line);

    if (argv == NULL)
        return (0);

    pid = fork();

    if (pid == -1)
    {
        perror("fork");
        free_argv(argv);
        return (1);
    }

    if (pid == 0)
    {
        execve(argv[0], argv, environ);
        perror(prog);
        exit(EXIT_FAILURE);
    }

    if (waitpid(pid, &status, 0) == -1)
    {
        perror("waitpid");
        free_argv(argv);
        return (1);
    }

    free_argv(argv);
    return (0);
}
