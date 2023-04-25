#include "main.h"

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
