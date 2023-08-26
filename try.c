#include <stdio.h>
#include <stdarg.h>

int printf(const char *format, ...);

int printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    
    int count = 0;
    const char *ptr = format;
    
    while (*ptr != '\0')
    {
        if (*ptr == '%' && *(ptr + 1) == 'd')
        {
            int num = va_arg(args, int);
            printf("%d", num);
            count++;
            ptr += 2;
        }
        else if (*ptr == '%' && *(ptr + 1) == 'i')
        {
            int num = va_arg(args, int);
            printf("%i", num);
            count++;
            ptr += 2;
        }
        else
        {
            putchar(*ptr);
            count++;
            ptr++;
        }
    }
    
    va_end(args);
    
    return count;
}
