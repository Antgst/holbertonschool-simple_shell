#include <stdio.h>
#include <stdlib.h>

/**
 * main - check the code
 * 
 * 
 * 
 */

int read_line (void)
{
    char *line = NULL;
    size_t buffer = 0;

    while(1)
    {
        printf("$ ");
        getline(&line, &buffer, stdin);
        
        printf("line: %sbuffer : %li\n", line, buffer);
    }
    free(line);
    return (0);
}
