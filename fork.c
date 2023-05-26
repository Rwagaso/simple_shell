#include <unistd.h>
#include <stdio.h>
/**
 * main - is a system call that is used to create processes
 * when child is created, both processes will execute next instruction
 *
 * Return: 0 (child)
 * otherwise -1(unsuccessful)
 */
int main(void)
{
	pid_t own_pid;
	pid_t pid;

	/*parent*/
	printf("This is me before fork\n");

	pid = fork();

	if (own_pid == -1)
	{
		perror("fail\n");
		return (1);
	}
	/*child*/
	printf("This is me after fork\n");
	pid = getpid();
	return (0);
}
