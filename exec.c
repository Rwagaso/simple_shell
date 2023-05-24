#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include "shell.h"
/**
 * main - Is A system call (execve) that permits
 * a program to execute another program
 *
 * Return: 0 (success)
 */
int main(void)
{
	pid_t pid;

	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

	pid = fork();

	if (pid == -1)
	{
		printf("Before the execve system call\n");
		return (-1);
	}
	if (pid == 0)
	{
		int val = execve(argv[0], argv, NULL);

		if (val == -1)
			perror("Error:");
	}
	else
	{
		wait(NULL);
		printf("After the execve system call\n");
	}
	return (0);
}
