#include "shell.h"

/**
 * _strerror - Returns a string describing an error code.
 * @err: Error code.
 *
 * Return: Corresponding error message.
 */
char *_strerror(int err)
{
	if (err == ENOENT)
		return ("not found");
	if (err == EACCES)
		return ("Permission denied");
	if (err == EISDIR)
		return ("Is a directory");
	if (err == ENOTDIR)
		return ("Not a directory");
	if (err == ENOEXEC)
		return ("Exec format error");

	return ("Error");
}
