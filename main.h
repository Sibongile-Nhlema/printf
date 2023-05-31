#ifndef MAIN_H
#define MAIN_H

/*header files*/
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

/*memory allocation*/
#define BUFF_SIZE 1024
#define UNUSED(x) (void)(x)

/*sizes*/
#define S_LONG 2
#define S_SHORT 1

/*flags*/
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_SPACE 16
#define F_HASH 8
#define F_INT (1 << 5)

/**
 * struct format - struct op
 * @format: format
 * @function: function associated
 *
 * Description: store the format specifier and associated function
 */

typedef struct format
{
	char format;
	int (*function)(va_list, char[], int, int, int, int);
} format_t;

int _printf(const char *format, ...);
int print_handler(const char *formatt, int *ind, va_list list, char buffer[],
		int flags, int width, int prec, int size);
/****All functions used****/

/*chars & strings*/
int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/*number*/
int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_hexa(va_list types, char map_to[], char buffer[], int flags,
		char flag_ch, int width, int precision, int size);

/*non printable characters*/
int print_non_printable(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/*memory address*/
int print_pointer(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/*other specifiers*/
int get_width(const char *format, int *i, va_list list);

/*string in reverse*/
int print_reverse(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);
int get_flags(const char *format, int *i);

/*string in rot 13*/
int print_rot13string(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/*width handler*/
int hdl_write_char(char c, char buffer[], int flags,
		int width, int prec, int size);
int write_num(int is_negative, int ind, char buffer[],
		int flags, int width, int prec, int size);
int write_num_buff(int ind, char buffer[], int flags,
		int width, int prec, int length, char pad, char extra_c);
int write_unsgned(int is_negative, int ind, char buffer[],
		int flags, int width, int prec, int size);
int write_pointer(char buffer[], int ind, int length,
		int width, int flags, char pad, char extra_c, int pad_start);

/***Utilities***/
int is_printable(char c);
long int convert_size_unsignd(unsigned long int num, int size);
long int convert_size_num(long int num, int size);
int is_dgt(char c);
int apend_hex_code(char ascii_code, char buffer[], int i);

#endif
