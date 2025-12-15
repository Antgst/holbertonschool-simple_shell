#include <stdio.h>

/**
 * getline - Read an entire line from a stream
 * @linep: Address of a char * variable. The buffer may be allocated or
 * reallocated and *linep updated accordingly
 * @linecapp: Address of a size_t variable holding the current
 * buffer size; may be updated
 * @stream: The input stream to read from
 * 
 * Return: The number of characters read (including the trailing '\\n' if present),
 * or -1 on EOF or error. The buffer is NUL-terminated. The caller must free it
 */

ssize_t getline(char ** restrict linep, size_t * restrict linecapp,  FILE * restrict stream)
{
// Utiliser un buffer
// Utiliser malloc
// Utiliser realloc ?
}
