#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

/**
 * main - Prints the PPID of the current process
 *
 * Return: Always 0 if success
 */

int main(void)
{
    pid_t ppid;

    ppid = getppid();
    printf("%u\n", ppid);
    
    return (0);
}
