#include "main.h"
/**
 * print_integer - print integer value only.
 * @args: arguments list of arguments.
 * Return: number of printed chars
 */
int print_integer(va_list args)
{
	int i;
	int number;
	int printed_chars = 0;
	char number_buffer[65];

	number = va_arg(args, int);
	number_to_string(number, 10, number_buffer);

	for (i = 0; number_buffer[i]; i++)
	{
		_putchar(number_buffer[i]);
		printed_chars++;
	}

	return (printed_chars);
}

