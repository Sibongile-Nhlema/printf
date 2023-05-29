#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * print_handler - print arg based on type
 * @format: format of string
 * @list: List of arguments
 * @size: Size specifier
 * @prec: Precision specification
 * @width: get width
 * @flags: Calculate active flags
 * @buffer: Buffer
 * @ind: ind.
 *
 * Return: 1 or 2;
 */

int print_handler(const char *formatt, int *ind, va_list list, char buffer[],
		int flags, int width, int prec, int size)
{
	int i, unknown_length = 0, printed_chars = -1;
	format_t format_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	i = 0;
	while (format_types[i].format != '\0')
	{
		if (format[*ind] == format_types[i].format)
			return (format_types[i].fn(list, buffer, flags, width, prec, size));
		i++;
	}
	if (format_types[i].format == '\0')
	{
		if (format[*ind] == '\0')
			return (-1);
		unknown_length += write(1, "%%", 1);
		if (format[*ind - 1] == ' ')
			unknown_length += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (format[*ind] != ' ' && format[*ind] != '%')
				--(*ind);
			if (format[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknown_length += write(1, &format[*ind], 1);
		return (unknown_length);
	}
	return (printed_chars);
}
