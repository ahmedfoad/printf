#include "main.h"


/**
 * print_char - print a single character only.
 * @args: arguments list of arguments.
 * Return: number of printed chars
 */
int print_char(va_list args)
{
	char currentChar;
	int printed_chars = 0;

	currentChar = va_arg(args, int);
	_putchar(currentChar);
	printed_chars++;

	return (printed_chars);
}

