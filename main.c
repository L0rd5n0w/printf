#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main -function
 * Return:(0)Always
 */
int main(void)
{
	int len1;
	int len2;
	unsigned int you;
	void *addr;

	len1 = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	you = (unsigned int)INT_MAX + 1024;
	addr = (void *)0x7ffe637541f0;
	_printf("Length:[%d, %i]\n", len1, len1);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	_printf("Unsigned:[%u]\n", you);
	printf("Unsigned:[%u]\n", you);
	_printf("Unsigned octal:[%o]\n", you);
	printf("Unsigned octal:[%o]\n", you);
	_printf("Unsigned hexadecimal:[%x, %X]\n", you, you);
	printf("Unsigned hexadecimal:[%x, %X]\n", you, you);
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	_printf("Address:[%p]\n", addr);
	printf("Address:[%p]\n", addr);
	len1 = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	_printf("Len:[%d]\n", len1);
	printf("Len:[%d]\n", len2);
	_printf("Unknown:[%r]\n");
	printf("Unknown:[%r]\n");
	return (0);
}
