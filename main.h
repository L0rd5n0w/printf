#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - struct function
 *
 * @fmt: parameter
 * @fn: parameter
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: parameter
 * @fm_t: parameter
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int _handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);




int _print_char(va_list types, char buffer[], int flags, int width, int precision, int size);
int _print_string(va_list types, char buffer[], int flags, int width, int precision, int size);
int _print_percent(va_list types, char buffer[], int flags, int width, int precision, int size);


int _print_int(va_list types, char buffer[], int flags, int width, int precision, int size);
int _print_binary(va_list types, char buffer[], int flags, int width, int precision, int size);
int _print_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size);
int _print_octal(va_list types, char buffer[], int flags, int width, int precision, int size);
int _print_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size);
int _print_hexa_upper(va_list types, char buffer[], int flags, int width, int precision, int size);

int _print_hexa(va_list types, char map_to[],
char _buffer[], int flags, char flag_ch, int width, int precision, int size);


int _print_non_printable(va_list types, char buffer[], int flags, int width, int precision, int size);


int _print_pointer(va_list types, char buffer[], int flags, int width, int precision, int size);


int _get_flags(const char *format, int *i);
int _get_width(const char *format, int *i, va_list list);
int _get_precision(const char *format, int *i, va_list list);
int _get_size(const char *format, int *i);


int _print_reverse(va_list types, char buffer[], int flags, int width, int precision, int size);

int _print_rot13string(va_list types, char buffer[], int flags, int width, int precision, int size);


int _handle_write_char(char c, char buffer[], int flags, int width, int precision, int size);
int _write_number(int is_positive, int ind, char buffer[], int flags, int width, int precision, int size);
int _write_num(int ind, char bff[], int flags, int width, int precision, int length, char padd, char extra_c);
int _write_pointer(char buffer[], int ind, int length, int width, int flags, char padd, char extra_c, int padd_start);

int _write_unsgnd(int is_negative, int ind,
char _buffer[], int flags, int width, int precision, int size);


int _is_printable(char);
int _append_hexa_code(char, char[], int);
int _is_digit(char);

long int _convert_size_number(long int num, int size);
long int _convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
