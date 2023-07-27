#include "main.h"

/**
 * convert_to_base2 - converts a number in base 10 to base 2
 * @n: number in base 10
 *
 * Return: number in base 10
 */
int print_base2(unsigned int n)
{
	int digits = 0;

	if (n / 2 == 0)
	{
		digits += _putchar('0' + n % 2);
		return (digits);
	}
		
	digits += print_base2(n / 2);

	digits += _putchar('0' + n % 2);

	return (digits);
}
