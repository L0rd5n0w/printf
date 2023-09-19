#include "main.h"

/**
 * get_flags -function
 * @format: paramter
 * @i: parameter
 * Return:(0)Always
 */
int _get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int q;
	int curry;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curry = *i + 1; format[curry] != '\0'; curry++)
	{
		for (q = 0; FLAGS_CH[q] != '\0'; q++)
			if (format[curry] == FLAGS_CH[q])
			{
				flags |= FLAGS_ARR[q];
				break;
			}

		if (FLAGS_CH[q] == 0)
			break;
	}

	*i = curry - 1;

	return (flags);
}

