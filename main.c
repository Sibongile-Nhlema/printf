#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 * Return: Always 0
 */

int main(void)
{
	int len;
	int len2;
	unsigned int ui;
	void *addr;

	len = _printf("Printf a sentence using our custom printf function.\n");
	len2 = printf("Printf a sentence using standard printf.\n");

	ui = (unsigned int)INT_MAX + 1024;
	addr = (void *)0x7ffe637541f0;
	_printf("Length:[%d, %i]\n", len, len);
	printf("Standard: Length:[%d, %i]\n", len2, len2);
	_printf("Negative:[%d]\n", -762534);
	printf("Standard: Negative:[%d]\n", -762534);
	_printf("Unsigned:[%u]\n", ui);
	printf("Standard: Unsigned:[%u]\n", ui);
	_printf("Unsigned octal:[%o]\n", ui);
	printf("Standard: Unsigned octal:[%o]\n", ui);
	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	printf("Standard: Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	_printf("Character:[%c]\n", 'H');
	printf("Standard: Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("Standard: String:[%s]\n", "I am a string !");
	_printf("Address:[%p]\n", addr);
	printf("Standard: Address:[%p]\n", addr);
	len = _printf("Percent:[%%]\n");
	len2 = printf("Standard: Percent:[%%]\n");
	_printf("Len:[%d]\n", len);
	printf("Standard: Len:[%d]\n", len2);
	_printf("Unknown:[%r]\n");
	printf("Standard: Unknown:[%r]\n");
	return (0);
}
