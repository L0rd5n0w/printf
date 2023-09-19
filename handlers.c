#include "main.h"

/**
 * handle_write_char -function
 * @c: parameter
 * @buffer: parameter
 * @flags:  paramete
 * @width: parameter
 * @precision: parameter
 * @size: parameter
 * Return:(0)Always
 */
int handle_write_char(char c, char buffer[], int flags, int width, int precision, int size)
{
	int q = 0;
	char paddy = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		paddy = '0';

	buffer[q++] = c;
	buffer[q] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (q = 0; q < width - 1; q++)
			buffer[BUFF_SIZE - q - 2] = paddy;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - q - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - q - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}


/**
 * write_number -function
 * @is_negative: parameter
 * @ind: parameter
 * @buffer: parameter
 * @flags:  parameter
 * @width: parameter
 * @precision: parameter
 * @size: paramter
 * Return:(0)Always
 */
int write_number(int is_negative, int ind, char buffer[], int flags, int width, int precision, int size)
{
	int leng = BUFF_SIZE - ind - 1;
	char paddy = ' ';
	char extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		paddy = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, flags, width, precision,
		leng, padd, extra_ch));
}

/**
 * write_num -function
 * @ind: parameter
 * @buffer: parameter
 * @flags: parameter
 * @width: parameter
 * @prec: parameter
 * @length: parameter
 * @padd: parameter
 * @extra_c: parameter
 * Return:(0)Always
 */
int _write_num(int ind, char buffer[], int flags, int width, int prec, int length, char padd, char extra_c)
{
	int q;
	int paddstart = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' ';
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (q = 1; q < width - length + 1; q++)
			buffer[q] = padd;
		buffer[q] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], q - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--paddstart] = extra_c;
			return (write(1, &buffer[paddstart], q - paddstart) +
				write(1, &buffer[ind], length - (1 - paddstart)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}

/**
 * write_unsgnd - function
 * @is_negative: parameter
 * @ind: parameter
 * @buffer: parameter
 * @flags: parameter
 * @width: parameter
 * @precision: parameter
 * @size: parameter
 * Return:(0)Always
 */
int _write_unsgnd(int is_negative, int ind, char buffer[], int flags, int width, int precision, int size)
{

	int length = BUFF_SIZE - ind - 1,
	int q = 0;
	char paddy = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);

	if (precision > 0 && precision < length)
		paddy = ' ';

	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		paddy = '0';

	if (width > length)
	{
		for (q = 0; q < width - length; q++)
			buffer[q] = paddy;

		buffer[q] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], q));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
		}
	}

	return (write(1, &buffer[ind], length));
}

/**
 * write_pointer -function
 * @buffer: parameter
 * @ind: parameter
 * @length: parameter
 * @width: parameter
 * @flags: parameter
 * @padd: parameter
 * @extra_c: parameter
 * @padd_start: parameter
 * Return:(0)Always
 */
int _write_pointer(char buffer[], int ind, int length, int width, int flags, char padd, char extra_c, int padd_start)
{
	int q;

	if (width > length)
	{
		for (q = 3; q < width - length + 3; q++)
			buffer[q] = padd;
		buffer[q] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], q - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], q - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], q - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}

