#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>
/* #include "main.h" */



/**
 * unsigned_number_to_string - Convert unsigned long int into
 * ASCII code in decimal formate
 * @number: All the input digits that needs to be printed
 * @base: the base of the digits (i.e decimal or hexa ..)
 * @buffer: a pointer to a buffer what will print the digits
 * Return: void
 */
void unsigned_number_to_string(__uint64_t number, int base, char *buffer)
{
	int cur;
	int i;
	char buf[65];
	int digit;

	if (number == 0)
	{
		*buffer = '0';
		*buffer = 0;
		return;
	}

	for (i = 0; i < 65; i++)
		buf[i] = 0;

	cur = 0;
	while (number)
	{
		digit = number % base;
		if (digit >= 10)
			buf[cur++] = 'a' + (digit - 10);
		else
			buf[cur++] = (digit % base) + '0';

		number /= base;
	}

	for (i = cur - 1; i != 0; i--)
	{
		*buffer++ = buf[i];
	}

	*buffer++ = buf[0];
	*buffer = 0;
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

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
	printed_chars + 2;

	p = va_arg(args, void *);

	number_to_string((uint64_t)p, 16, number_buffer);

	for (i = 0; number_buffer[i]; i++)
	{
		_putchar(number_buffer[i]);
		printed_chars++;
	}

	return (printed_chars);
}

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

/**
 * print_decimal - print a decimal character only.
 * @is_long: equal(1) if it is long else equal(0)
 * @args: arguments list of arguments.
 * Return: number of printed chars
 */
int print_decimal(int *is_long, va_list args)
{
	int i;
	int64_t ul_number;
	int printed_chars = 0;
	char number_buffer[65];

	if (*is_long == 1)
		ul_number = va_arg(args, long);
	else
		ul_number = va_arg(args, int);

	number_to_string(ul_number, 10, number_buffer);

	for (i = 0; number_buffer[i]; i++)
	{
		_putchar(number_buffer[i]);
		printed_chars++;
	}

	return (printed_chars);
}

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

/**
 * print_all_formats - writes  all input characters to stdout
 * @format: All the input characters that needs to be printed
 * @args: dynamic arguments
 * Return: the number of printed characters.
 */
int print_all_formats(const char *format, va_list args)
{
	int *is_argument;
	int *is_long;
	int *is_flag_end;

	int count = 0;
	int printed_chars = 0;

	*is_argument = 0; 
	*is_long = 0; 
	*is_flag_end = 1;

	for (count = 0; format[count] != '\0'; count++)
	{
		if (*is_argument == 0)
		{
			if (format[count] == '%')
				*is_argument = 1;
			else
			{
				_putchar(format[count]);
				printed_chars++;
			}
		}
		else if (*is_argument == 1)
			printed_chars +=  print_all_format_checker(
			format[count],
			args,
			is_argument,
			is_long,
			is_flag_end);

		if (*is_flag_end == 1)
		{
			*is_argument = 0;
			*is_long = 0;
		}
		else
			*is_flag_end = 1;
	}
	return (printed_chars);
}

/**
 * print_all_format_checker - check the character type then print
 * @format: All the input characters that needs to be printed
 * @args: dynamic arguments
 * @is_argument: (1) if the is_argument is true else, equal (0).
 * @is_long: (1) if the is_long is true else, equal (0).
 * @is_flag_end: (1) if the is_flag_end is true else, equal (0).
 * Return: the number of printed characters.
 */
int print_all_format_checker(char format, va_list args, int *is_argument,
				int *is_long, int *is_flag_end)
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

/**
 * number_to_string - Convert number to
 * ASCII code in decimal format.
 * @number: All the input digits that needs to be printed
 * @base: the base of the digits (i.e decimal or hexa ..)
 * @buffer: a pointer to a buffer what will print the digits
 * Return: void
 */
void number_to_string(__uint64_t number, int base, char *buffer)
{
	if ((int)number < 0)
	{
		*buffer++ = '-';
		number = -number;
	}
	unsigned_number_to_string(number, base, buffer);
}

int _putchar(char c);
void unsigned_number_to_string(__uint64_t number, int base, char *buffer);
void number_to_string(__uint64_t number, int base, char *buffer);
int print_all_formats(const char *format, va_list args);
int print_decimal(int *is_long, va_list args);
int print_unsigned_int(va_list args);
int print_unsigned_hexadecimal(int *is_long, va_list args);
int print_integer(va_list args);
int print_pointer(va_list args);
int print_string(va_list args);
int print_char(va_list args);
int _printf(const char *format, ...);
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len;
	int len2;
	unsigned int ui;
	void *addr;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	ui = (unsigned int)INT_MAX + 1024;
	addr = (void *)0x7ffe637541f0;
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	_printf("Unsigned:[%u]\n", ui);
	printf("Unsigned:[%u]\n", ui);
	_printf("Unsigned octal:[%o]\n", ui);
	printf("Unsigned octal:[%o]\n", ui);
	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	_printf("Address:[%p]\n", addr);
	printf("Address:[%p]\n", addr);
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	return (0);
}
