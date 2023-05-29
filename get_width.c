#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string
 * @i: List of arguments
 * @list: list of arguments
 *
 * Return: width
 */

int get_width(const char *format, int *i, va_list list)
{
	int current_i = *i + 1;
	int width = 0;

	while (is_digit(format[current_i]))
	{
		width *= 10;
		width += format[current_i] - '0';
		current_i++;
	}
	if (format[current_i] == '*')
	{
		current_i++;
		width = va_arg(list, int);
	}
	*i = current_i - 1;
	return (width);
}
