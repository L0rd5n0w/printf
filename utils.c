#include "main.h"

/**
 * is_printable -function
 * @c: parameter
 * Return:(0)Always
 */
int _is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code -function
 * @buffer: parameter
 * @i: parameter
 * @ascii_code: parameter
 * Return:(0)Always
 */
int _append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";


	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit -function
 * @c: parameter
 * Return:(0)Always
 */
int _is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number -function
 * @num: parameter
 * @size: parameter
 * Return:(0)Always
 */
long int _convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd -function
 * @num: parameter
 * @size: parameter
 * Return:(0)Always
 */
long int _convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

