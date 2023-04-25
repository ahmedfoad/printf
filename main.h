#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>

int _putchar(char c);
void number_to_string(__uint64_t number, int base, char *buffer);
int print_all_format_checker(char format, va_list args, int *is_argument, int *is_long, int *is_flag_end);
int print_all_formats(const char *format, va_list args);
int print_char(va_list args);
int print_decimal(int *is_long, va_list args);
int _printf(const char *format, ...);
int print_integer(va_list args);
int print_pointer(va_list args);
int print_string(va_list args);
int print_unsigned_hexadecimal(int *is_long, va_list args);
int print_unsigned_int(va_list args);
void unsigned_number_to_string(__uint64_t number, int base, char *buffer);

#endif /* MAIN_H */

