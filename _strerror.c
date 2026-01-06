#include "shell.h"

/**
 * _strerror - Returns a string describing an error code
 * @err: Error code
 *
 * Return: Corresponding error message
 */
char *_strerror(int err)
{
	if (err == ENOENT)
		return ("not found");

	return ((char *)strerror(err));
}
