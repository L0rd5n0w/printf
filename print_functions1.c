#include "main.h"

/**
 * _print_unsigned -function
 * @types: parameter
 * @buffer: parameter
 * @flags:  parameter
 * @width: parameter
 * @precision: parameter
 * @size: parameter
 * Return:(0)Always
 */
int _print_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int q = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = _convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[q--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[q--] = (num % 10) + '0';
		num /= 10;
	}

	q++;

	return (_write_unsgnd(0, q, buffer, flags, width, precision, size));
}


/**
 * _print_octal -function
 * @types: parameter
 * @buffer: parameter
 * @flags:  parameter
 * @width: parameter
 * @precision: parameter
 * @size: parameter
 * Return:(0)Always
 */
int _print_octal(va_list types, char buffer[], int flags, int width, int precision, int size)
{

	int q = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int), init_num = num;

	UNUSED(width);

	num = _convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[q--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[q--] = (num % 8) + '0';
		num /= 8;
	}
	if (flags & F_HASH && init_num != 0)
		buffer[q--] = '0';
	q++;
	return (_write_unsgnd(0, q, buffer, flags, width, precision, size));
}


/**
 * _print_hexadecimal -function
 * @types: parameter
 * @buffer: parameter
 * @flags:  parameter
 * @width: parameter
 * @precision: parameter
 * @size: parameter
 * Return:(0)Always
 */
int _print_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	return (_print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}


/**
 * _print_hexa_upper -function
 * @types: parameter
 * @buffer: parameter
 * @flags:  parameter
 * @width: parameter
 * @precision: parameter
 * @size: parameter
 * Return:(0)Always
 */
int _print_hexa_upper(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	return (_print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}


/**
 * _print_hexa -function
 * @types: parameter
 * @map_to: parameter
 * @buffer: parameter
 * @flags:  parameter
 * @flag_ch: parameter
 * @width: parameter
 * @precision: parameter
 * @size: parameter
 * @size: parameter
 * Return: parameter
 */
int _print_hexa(va_list types, char map_to[], char buffer[], int flags, char flag_ch, int width, int precision, int size)
{
	int q = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = _convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[q--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[q--] = map_to[num % 16];
		num /= 16;
	}
	if (flags & F_HASH && init_num != 0)
	{
		buffer[q--] = flag_ch;
		buffer[q--] = '0';
	}
	q++;
	return (_write_unsgnd(0, q, buffer, flags, width, precision, size));
}
