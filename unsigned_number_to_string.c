#include "main.h"


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
