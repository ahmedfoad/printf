#include "main.h"

/**
 * _printf - Custom printf function/
 * @format: a pointer to array of chars that needs to be printed.
 * Return: number of printed chars
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;

	va_start(args, format);

	printed_chars = print_all_formats(format, args);
	va_end(args);

	return (printed_chars);
}

