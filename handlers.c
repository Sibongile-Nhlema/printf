#include "main.h"
#include <stdio.h>

/*******Write Handle******/

/**
 * hdl_write_char - Prints a string
 * @c: char
 * @precision: precision specifier
 * @buffer: buffer array
 * @size: size specifier
 * @width: get width
 * @flags:  calculate active flags
 *
 * Return: Number of chars
 */

int hdl_write_char(char c, char buffer[],
		int flags, int width, int precision, int size)
{
	char pad = ' ';
	int i = 0;

	UNUSED(size);
	UNUSED(precision);

	if (flags & F_ZERO)
		pad = '0';
	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		i = 0;
		while (i < width - 1)
		{
			buffer[BUFF_SIZE - i - 2] = pad;
			i++;
		}
		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1)
					+ write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}

