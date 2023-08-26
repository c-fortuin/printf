#include <stdio.h>

void handleconversion(int num, ...);

void handleconversion(int num, ...)
{
	printf("%d\n", num);
	printf("%i\n", num);
}
