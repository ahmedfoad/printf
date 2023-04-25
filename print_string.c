#include "main.h"

/**
 * print_string - print a string of character only.
 * @args: arguments list of arguments.
 * Return: number of printed chars
 */
int print_string(va_list args)
{
	int i;
	int printed_chars = 0;
	const char *s = va_arg(args, const char *);

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		printed_chars++;
		i++;
	}

	return (printed_chars);
}

