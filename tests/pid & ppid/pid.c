#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

/**
 * main - Prints the PID of the current process
 *
 * Return: Always 0 if success
 */

int main(void)
{
    pid_t my_pid;

    my_pid = getpid();
    printf("%d\n", (int)my_pid);

    return (0);
}
