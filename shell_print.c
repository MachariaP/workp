#include "main.h"
#include <string.h>
#include <unistd.h>


void shell_print(const char *c)
{
	write(1, c, strlen(c));
}

