#include "main.h"

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
		return (0);

	while (str[i])
	{
		printed_chars += _putchar(str[i]);
		i++;
	}

	return (printed_chars);
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

	if (!format || (*format == '%' && !*(format + 1)))
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
