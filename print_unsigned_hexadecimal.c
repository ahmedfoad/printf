#include "main.h"


/**
 * print_unsigned_hexadecimal - print unsigned hexadecimal only.
 * @is_long: equals(1) if the number is long else equal(0).
 * @args: arguments list of arguments.
 * Return: number of printed chars
 */
int print_unsigned_hexadecimal(int *is_long, va_list args)
{
	int i;
	int64_t ul_number;
	int printed_chars = 0;
	char number_buffer[65];

	if (*is_long == 1)
		ul_number = va_arg(args, unsigned long);
	else
		ul_number = va_arg(args, int);

	number_to_string(ul_number, 16, number_buffer);
	for (i = 0; number_buffer[i]; i++)
	{
		_putchar(number_buffer[i]);
		printed_chars++;
	}

	return (printed_chars);
}
