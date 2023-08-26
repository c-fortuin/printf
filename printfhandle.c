#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int count = 0;
	const char *p = format;

	while (*p != '\0')
	{
		if (*p == '%' && *(p + 1) == 'd')
		{
			int value = va_arg(args, int);
			printf("%d", value);
			p++;
			count++;
		}
		else if (*p == '%' && *(p + 1) == 'i')
		{
			int value = va_arg(args, int);
			printf("%i", value);
			p++;
			count++;
		}
		else
		{
			putchar(*p);
		}
		p++;
	}
	va_end(args);
}
