#include <stdio.h>
 
#include <kernel/tty.h>
 
void putchar(int ic)
{
	char c = (char) ic;
	terminal_write(&c, sizeof(c));
}
