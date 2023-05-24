#include "shell.h"

/**
 * _strlen - this returns the string length
 * @h: the string lenth to be checked
 *
 * Return: the integer length of te string
 */
int _strlen(char *s)
{
	int i = 0;

	/*the condition*/
	if (!s)
	{
		return (0);
	}
	while (*s++)
		i++;
	return (i);
}
/**
 * _strcmp - this does the comparison of two strings
 *
 * @s1: string number 1
 * @s2: string number 2
 *
 * Return: (-) negattive is s1<s2,
 * otherwise (+) if s1>s2.
 * 0 if s1==s2.
 */
int_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s2++;
		s1++;
	}
	if (*s1 == *s2)
	{
		return (0);
	}
	else
		return (*s1 < *s2 ? -1 : 1);

}
/**
 * starts_with - this checks whether needle starts with
 * a haystack
 * @needle: is the substring to be found
 *
 * @haystack: refers to the string to search
 *
 * Return: the adress, or NULL.
 */

char *starts_with(constant char *haystack, constr char *needle)
{
	while (*needle)
	{
		if (*needle++ != *haystack++)
			return (NULL);
	}
	return ((char *)haystack);
}
/**
 * _stract - this ,two strings
 * @src: is the buffer source
 * @dest: refers to place of buffer
 *
 * Return: the pointer to place of buffer
 */

char *_stract(char *dest, char *src)
{
	char *rett = dest;

	while (*dest)
	{
		dest++;
	}
	while (*src)
		*dest++ = *src++;

	*dest = *src;
	return (rett);
}

