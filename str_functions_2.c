#include "shell.h"

/**
 * _puts - functiont to write string to standard out.
 * @str: string.
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

/**
 * prstr - prints multiple strings.
 * @args: pointer.
 *
 * Return: int.
 */
int prstr(va_list *args)
{
	int n = 0;
	char *a;

	a = va_arg(*args, char *);
	while (*a != '\0')
	{
		_putchar(*a);
		n++;
		a++;
	}

	return (n);
}

/**
 * _putchar - writes the character c to sterr.
 * @c: character.
 *
 * Return: int.
 */
int _putchar(char c)
{
	return (write(2, &c, 1));
}
