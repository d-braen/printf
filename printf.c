#include "main.h"
#include <limits.h>

/**
 * print_string - prints string to output stream
 * @str: string to be printed
 *
 * Return: number of characters printed
 */
int print_string(const char *str)
{
	int i = 0;
	int printed_chars = 0;

	if (!str)
	{
		printed_chars += _putchar('(');
		printed_chars += _putchar('n');
		printed_chars += _putchar('u');
		printed_chars += _putchar('l');
		printed_chars += _putchar('l');
		printed_chars += _putchar(')');
		return (printed_chars);
	}

	while (str[i])
	{
		printed_chars += _putchar(str[i]);
		i++;
	}

	return (printed_chars);
}

/**
 * print_number - prints an integer to stdout
 * @num: number
 *
 * Return: number of digits printed
 */
int print_number(int num)
{
	int n = num;
	int div = -1;
	int digits = 0;

	if (num > 0)
	{
		num *= -1;
		n = num;
	}
	while (n <= -10)
	{
		n = n / 10;
		div *= 10;
	}

	while (div)
	{
		_putchar('0' + num / div);
		num %= div;
		div /= 10;
		digits++;
	}

	return (digits);
}

/**
 * _printf - print formatted string to std ouput
 * @format: char string with format
 *
 * Return: number of characters printed to output stream
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0, total_chars = 0;

	if (!format || (*format == '%' && (!*(format + 1))))
		return (-1);
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
			{
				i++;
				total_chars += _putchar('%');
			}
			else if (format[i + 1] == 'c')
			{
				i++;
				total_chars += _putchar(va_arg(ap, int));
			}
			else if (format[i + 1] == 's')
			{
				i++;
				total_chars += print_string(va_arg(ap, char *));
			}
			else if (format[i + 1] == 'd' || format[i + 1] == 'i')
			{
				total_chars += print_number(va_arg(ap, int));
				i++;
			}
			else
			{
				total_chars += _putchar('%');
			}
		}
		else
		{
			total_chars += _putchar(format[i]);
		}
		i++;
	}
	va_end(ap);
	return (total_chars);
}
