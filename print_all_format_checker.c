#include "main.h"
/**
 * print_all_format_checker - check the character type then print
 * @format: All the input characters that needs to be printed
 * @args: dynamic arguments
 * @is_argument: (1) if the is_argument is true else, equal (0).
 * @is_long: (1) if the is_long is true else, equal (0).
 * @is_flag_end: (1) if the is_flag_end is true else, equal (0).
 * Return: the number of printed characters.
 */
int print_all_format_checker(char format, va_list args,
int *is_argument, int *is_long, int *is_flag_end)
{
	int printed_chars = 0;

	if (format == '%')
	{
		_putchar(format);
		printed_chars++;
		*is_argument = 0;
	}
	else if (format == 'c')
		printed_chars += print_char(args);
	else if (format == 's')
		printed_chars += print_string(args);
	else if (format == 'l')
	{
		*is_long = 1;
		*is_flag_end = 0;
	}
	else if (format == 'i')
		printed_chars += print_integer(args);
	else if (format == 'u')
		printed_chars += print_unsigned_int(args);
	else if (format == 'd')
		printed_chars += print_decimal(is_long, args);
	else if (format == 'x')
		printed_chars += print_unsigned_hexadecimal(is_long, args);
	else if (format == 'p')
		printed_chars += print_pointer(args);
	else
	{
		_putchar(format);
		printed_chars++;
		*is_argument = 0;
	}
	return (printed_chars);
}

