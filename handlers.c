#include "main.h"
#include <stdio.h>

/*******Write Handle******/

/**
 * hdl_write_char - Prints a string
 * @c: char
 * @prec: precision specifier
 * @buffer: buffer array
 * @size: size specifier
 * @width: get width
 * @flags:  calculate active flags
 *
 * Return: Number of chars
 */

int hdl_write_char(char c, char buffer[],
		int flags, int width, int prec, int size)
{
	char pad = ' ';
	int i = 0;

	UNUSED(size);
	UNUSED(prec);

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

/*****write number*****/

/*
 * write_num - prints string
 * @ind: char types
 * @is_negative: arguments
 * width: get width
 * size: Size specifier
 * prec: precision specifier
 * @flags:  calculate active flags
 * @buffer: Buffer array
 *
 * Return: Number of chars
 */

int write_num(int is_negative, int ind, char buffer[],
		int flags, int width, int prec, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char pad = ' ', extra_ch = 0;

	UNUSED(size);
	if ((flags & F_ZERO) && !(flags & F_MINUS))
	{
		pad = '0';
	}
	if (is_negative)
	{
		extra_ch = '-';
	}
	else if (flags & F_PLUS)
	{
		extra_ch = '+';
	}
	else if (flags & F_SPACE)
	{
		extra_ch = ' ';
	}

	return (write_num_buff(ind, buffer, flags, width, prec,
				length, pad, extra_ch));
}

/**
 * write_num_buff - uses buffe to write number
 * @buffer: Buffer
 * @ind: Index where number starts buffer
 * @flags: Flags
 * @width: width
 * @prec: Precision specifier
 * @length: Number length
 * @pad: Padding char
 * @extra_c: Extra char
 *
 * Return: Number of char
 */

int write_num_buff(int ind, char buffer[], int flags,
		int width, int prec, int length, char pad, char extra_c)
{
	int i, pad_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = pad = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = pad;
		buffer[i] = '\0';
		if (flags & F_MINUS && pad == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length)
					+ write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && pad == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], i - 1) +
					write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && pad == '0')
		{
			if (extra_c)
				buffer[--pad_start] = extra_c;
			return (write(1, &buffer[pad_start], i - pad_start) +
					write(1, &buffer[ind], length - (1 - pad_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}

/**
 * write_unsigned - writes unsigned number
 * @ind: Index at which number start buffer
 * @is_negative: Num indicating if num is negative
 * @buffer: Array of chars
 * @size: Size specifier
 * @prec: Precision specifier
 * @width: Width specifier
 * @flags: Flags specifiers
 *
 * Return: Number of written chars
 */

int write_unsigned(int is_negative, int ind, char buffer[],
		int flags, int width, int prec, int size)
{
	int length = BUFF_SIZE - ind - 1, i = 0;
	char pad = ' ';

	UNUSED(size);
	UNUSED(is_negative);

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);
	if (prec > 0 && prec < length)
		pad = ' ';
	while (prec > length)
	{
		buffer[--ind] = '0';
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pad = '0';
	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = pad;
		buffer[i] = '\0';
		if (flags & F_MINUS)
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
		}
	}
	return (write(1, &buffer[ind], length));
}

/*
 * write_pointer - Write a memory address
 * @buffer: Arrays of chars
 * @ind: Index where number starts in the buffer
 * @length: Length of number
 * @width: Width specifier
 * @extra_c: Char representing extra char
 * @flags: Flags specifier
 * @pad_start: Index where padding should start
 * @pad: Char representing padding
 *
 * Return: Number of written chars.
 */

int write_pointer(char buffer[], int ind, int length,
		int width, int flags, char pad, char extra_c, int pad_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = pad;
		buffer[i] = '\0';
		if (flags & F_MINUS && pad == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && pad == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && pad == '0')
		{
			if (extra_c)
				buffer[--pad_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[pad_start], i - pad_start) +
					write(1, &buffer[ind], length - (1 - pad_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
