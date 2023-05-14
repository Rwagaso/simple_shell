#include <unistd.h>
#include <stdio.h>
/**
 * main - writing a function that has a unique process ID
 * Process Identifier (PID)
 *
 * Return: 0 (success)
 */
int main(void)
{
	pid_t own_pid;

	own_pid = getpid();
	printf("own_pid is %u\n", own_pid);

	return (0);
}

