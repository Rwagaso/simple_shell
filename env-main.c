#include "shell.h"
#include <stdio.h>

/**
 * main - this is where the enviornment
 * gets printed
 * @av: this deliver system functionality
 * @env: this is the environment
 *
 * @ac: this is the accepted code
 *
 * Return: 0
 */
int main(int ac, char **av, char **env)
{
	unsigned int k;

	k = 0;
	while (env[k] != NULL)
	{
		printf("%s\n", env[k]);
		k++;
	}
return (0);
}

