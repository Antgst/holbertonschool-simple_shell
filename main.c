#include "shell.h"

/**
 * main - Entry point for the simple shell
 * @argc: The number of arguments passed to the program
 * @argv: An array of the arguments ([0] is the program name)
 * 
 * Return : 0 on success
 */

int main(int argc, char **argv)
{
    char *line = NULL;
    size_t bufcap = 0;
    ssize_t nread;
    unsigned long int line_no = 0;
    (void)argc;

    while (1)
    {
        if (stdin_isatty() == 1)
            print_prompt();
        
        nread= read_line(&line, &bufcap);

        if (nread == -1)
        {
            free(line);
            return (0);
        }
        line_no++;

        remove_newline(line);

        if (is_blank_line(line) == 1)
            continue;

        execute_simple(line, argv[0], line_no);
    }
    free(line);
    return (0);
}
