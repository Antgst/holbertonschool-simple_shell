#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - check the code
 * 
 * 
 * 
 */

int main (void)
{
    char *line = NULL;
    size_t buffer = 0;

    while(1)
    {
        printf("$ ");
        getline(&line, &buffer, stdin);
        
        printf("line: %s buffer : %li\n", line, buffer);
    }
    free(line);
    return (0);
}
