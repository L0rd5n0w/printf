#include "main.h"

/**
 * _get_precision -function
 * @format: parameter
 * @i: parameter
 * @list: parameter
 * Return:(0)Always
 */
int _get_precision(const char *format, int *i, va_list list)
{
	int curry = *i + 1;
	int precision = -1;

	if (format[curry] != '.')
		return (precision);

	precision = 0;

	for (curry += 1; format[curry] != '\0'; curry++)
	{
		if (is_digit(format[curry]))
		{
			precision *= 10;
			precision += format[curry] - '0';
		}
		else if (format[curry] == '*')
		{
			curry++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curry - 1;

	return (precision);
}

