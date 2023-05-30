#include "main.h"

/**
 * get_flags - Calculates active flag
 * @format: String format which print argument
 * @i: take a parameter
 * Return: Flags
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # '' */
	/* 1 2 4 8  16 */
	int j, current_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (current_i = *i + 1; format[current_i] != '\0'; current_i++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
		if (format[current_i] == FLAGS_CH[j])
		{
			flags |= FLAGS_ARR[j];
			break;
		}
		if (FLAGS_CH[j] == 0)
			break;
	}
	*i = current_i - 1;
	return (flags);
}
