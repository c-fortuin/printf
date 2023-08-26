#include <stdio.h>
#include <stdarg.h>
#include "main.h"
int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0;
    const char *ptr = format;

    while (*ptr != '\0')
    {
        if (*ptr == '%')
        {
            ptr++;

            switch (*ptr)
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
                case 'i':
                {
                    int num = va_arg(args, int);
                    printf("%d", num);
                    count++;
                    break;
                }
                default:
                    break;
            }
        }
        else
        {
            putchar(*ptr);
            count++;
        }

        ptr++;
    }

    va_end(args);

    return count;
}

int main()
{
    _printf("Hello, %s! The answer is %d.", "world", 42);
    return 0;
}

