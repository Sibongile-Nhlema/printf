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

/****All functions used****/

/*chars & strings*/

/*number*/

/*non printable characters*/

/*memory address*/

/*other specifiers*/

/*string in reverse*/

/*string in rot 13*/

/*width handler*/
int hdl_write_char(char c, char buffer[], int flags,
		int width, int prec, int size);
int write_num(int is_negative, int ind, char buffer[],
		int flags, int width, int prec, int size);
int write_num_buff(int ind, char buffer[], int flags,
		int width, int prec, int length, char pad, char extra_c);
int write_unsigned(int is_negative, int ind, char buffer[],
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