#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main()
{
	char buffer[BUFFER_SIZE];
	int bytesRead;

	write(STDOUT_FILENO, buffer, bytesRead);

	return (0);
}
