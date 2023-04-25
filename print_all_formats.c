#include "main.h"


/**
 * print_all_formats - writes  all input characters to stdout
 * @format: All the input characters that needs to be printed
 * @args: dynamic arguments
 * Return: the number of printed characters.
 */
int print_all_formats(const char *format, va_list args)
{
	int printed_chars = 0;
	int is_argument = 0;
	int is_long = 0;
	int is_flag_end = 1;
	int count;

	count = 0;
	while (format[count] != '\0')
	{
		if (is_argument == 0)
		{
			if (format[count] == '%')
				is_argument = 1;
			else
			{
				_putchar(format[count]);
				printed_chars++;
			}
		}
		else if (is_argument == 1)
		{
			if (format[count] == '%')
			{
				_putchar(format[count]);
				printed_chars++;
				is_argument = 0;
			}
			else
			{
				printed_chars +=  print_all_format_checker(format[count], args, &is_argument, &is_long, &is_flag_end);
			}

			if (is_flag_end == 1)
			{
				is_argument = 0;
				is_long = 0;
			}
			else
			{
				is_flag_end = 1;
			}
		}

		count++;
	}
	return printed_chars;
}

