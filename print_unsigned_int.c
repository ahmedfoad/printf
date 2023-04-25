#include "main.h"

/**
 * print_unsigned_int - print unsigned int only.
 * @args: arguments list of arguments.
 * Return: number of printed chars
 */
int print_unsigned_int(va_list args)
{
	int i;
	int printed_chars = 0;
	unsigned int number;
	char number_buffer[65];

	number = va_arg(args, unsigned int);

	number_to_string(number, 10, number_buffer);
	for (i = 0; number_buffer[i]; i++)
	{
		_putchar(number_buffer[i]);
		printed_chars++;
	}

	return (printed_chars);
}
