#include "main.h"
#include <stdio.h>
/**
 * _printf - function that produces output according to a format
 * @format: format
 * Return: Return numbers of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);

	if (*format == NULL)
		return (-1);

	while (*format != '\0')
	{
		if (format != '%')
		{
			write(1, format, 1);
		}

		format++;
	}

	return (count);
}
