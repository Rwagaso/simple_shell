#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

/**
 * main - this system call  suspends execution of the calling
 *  process until one of its children terminates.
 *
 *  Return: 0
 */
int main(void)
{
	pid_t child_pid;

	/*This refers to the child process creation*/
	child_pid = fork();

	/*if the fork fails*/
	if (child_pid == -1)
	{
		perror("Process Fail:\n");
		return (1);
	}
	/*the child process*/
	if (child_pid == 0)
	{
		printf("i am your child\n");
	}
	/*the parent process*/
	else
	{
		wait(NULL);
		sleep(7);
		printf("wait for me, i am your parent\n");
	}
	return (0);
}
