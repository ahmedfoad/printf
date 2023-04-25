#include "main.h"

/**
 * print_pointer - print a pointer only.
 * @args: arguments list of arguments.
 * Return: number of printed chars
 */
int print_pointer(va_list args)
{
	int i;
	void *p;
	int printed_chars = 0;
	char number_buffer[65];

	_putchar('0');
	_putchar('x');
	printed_chars = printed_chars + 2;

	p = va_arg(args, void *);

	number_to_string((uint64_t)p, 16, number_buffer);

	for (i = 0; number_buffer[i]; i++)
	{
		_putchar(number_buffer[i]);
		printed_chars++;
	}

	return (printed_chars);
}

