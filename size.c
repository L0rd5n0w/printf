#include "main.h"

/**
 * get_size -function
 * @format: parameter
 * @i: parameter
 * Return:(0)Always
 */
int _get_size(const char *format, int *i)
{
	int curry = *i + 1;
	int size = 0;

	if (format[curry] == 'l')
		size = S_LONG;
	else if (format[curry] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curry - 1;
	else
		*i = curry;

	return (size);
}
