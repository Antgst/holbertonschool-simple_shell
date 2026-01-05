#include "shell.h"

/**
 * read_line - Read one line from STDIN, using getline
 * @line: Address of the buffer where the line will be stored
 * @bufcap: Address of the current allocated size of the buffer
 * 
 * Return: The number of characters read including '\n' or -1 on EOF or error if it failed
 */

ssize_t read_line(char **line, size_t *bufcap)
{
    ssize_t nread;

    nread = getline(line, bufcap, stdin);
    return (nread);
}
