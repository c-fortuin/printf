#include "main.h"
#include <stdio.h>
#include <stdarg.h>
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

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 'c':
					{
						int c = va_arg(args, int);
						putchar(c);
						count++;
						break;
					}
				case 's':
					{
						char *s = va_arg(args, char *);
						while (*s != '\0')
						{
							putchar(*s);
							s++;
							count++;
						}
						break;
					}
				case '%':
					{
						putchar('%');
						count++;
						break;
					}
				case 'd':
					{
						int num = va_arg(args, int);
                                                printf("%d", num);
                                                count++;
                                                break;
					}
				case 'i':
					{
						int num = va_arg(args, int);
						printf("%i", num);
						count++;
						break;
					}
				default:
					{
						putchar('%');
						putchar(*format);
						count += 2;
						break;
					}
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);

	return (count);
}
