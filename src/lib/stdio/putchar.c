#include <stdio.h>
 
#include <console/tty.h>
 
void putchar(int ic)
{
	char c = (char) ic;
	terminal_write(&c, sizeof(c));
}
