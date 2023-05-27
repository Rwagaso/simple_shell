#include "shell.h"

/**
 * _erratoi - this is convertstring to an integer
 * @s: thetring to be converted
 * Return: 0 if no numbers intring, converted number otherwise
 *       -1 on error
 */
int _erratoi(char *s)
{
	int c = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;
	for (c = 0; s[c] != '\0'; c++)
	{
		if (s[c] >= '0' && s[c] <= '9')
		{
			result *= 10;
			result += (s[c] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - this prints an error message
 * @info: the parameter and return infotruct
 * @estr:tring containing specified error type
 * Return: 0 if no numbers intring, converted number otherwise
 *        -1 on error
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - the function prints a decimal (integer) number (base 10)
 * @input: the input
 * @fd: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int c, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (c = 1000000000; c > 1; c /= 10)
	{
		if (_abs_ / c)
		{
			__putchar('0' + current / c);
			count++;
		}
		current %= c;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - is the converter function, a clone of itoa
 * @num: this is the number
 * @base: base
 * @flags: this is argument flags
 *
 * Return:tring
 */
char *convert_number(long int num, int base, int flags)
{
static char *array;
static char buffer[50];
	char ign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
        ign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (ign)
		*--ptr = ign;
	return (ptr);
}

/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @buf: address of thetring to modify
 *
 * Return: Always 0;
 */
void remove_comments(char *buf)
{
	int c;

	for (c = 0; buf[c] != '\0'; c++)
		if (buf[c] == '#' && (!c || buf[c - 1] == ' '))
		{
			buf[c] = '\0';
			break;
		}
}


