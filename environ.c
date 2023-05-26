#include "shell.h"

/**
 * _myenv - this prints current environment
 * @info: this has potential arguments.which is used to maintain
 * constant function of prototype.
 * Return: Always 0 succes..
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - This gets a value of the environ variable
 * @info: This has potential arguments.
 *
 * @name: is the env variable name
 *
 * Return: must return the value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - this ushers in the new environment variable,
 * or modify an existing one.
 * @info: this has potential arguments. Used to maintain
 * constant function prototype.
 *
 *  Return: Always 0 successfully
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - do away with an environment variable
 * @info: this has potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0 successfully
 */
int _myunsetenv(info_t *info)
{
	int b;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (b = 1; b <= info->argc; b++)
		_unsetenv(info, info->argv[b]);

	return (0);
}

/**
 * populate_env_list - populates env linked list
 * @info: Structure containing potential arguments.
 * Used to maintain constant function prototype.
 * Return: Always 0 successfully
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t b;

	for (b = 0; environ[b]; b++)
		add_node_end(&node, environ[b], 0);
	info->env = node;
	return (0);
}

