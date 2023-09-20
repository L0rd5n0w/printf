#include "main.h"
/**
 * _handle_print -function
 * @fmt: parameter
 * @list: parameter
 * @ind: parameter
 * @buffer: parameter
 * @flags: parameter
 * @width: parameter
 * @precision: parameter
 * @size: parameter
 * Return:(0)Always
 */
int _handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int q;
	int unknow_len = 0;
	int printed_chars = -1;


	fmt_t fmt_types[] = {
		{'c', _print_char}, {'s', _print_string}, {'%', _print_percent},
		{'i', _print_int}, {'d', _print_int}, {'b', _print_binary},
		{'u', _print_unsigned}, {'o', _print_octal}, {'x', _print_hexadecimal},
		{'X', _print_hexa_upper}, {'p', _print_pointer}, {'S', _print_non_printable},
		{'r', _print_reverse}, {'R', _print_rot13string}, {'\0', NULL}
	};
	for (q = 0; fmt_types[q].fmt != '\0'; q++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[q].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[q].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
