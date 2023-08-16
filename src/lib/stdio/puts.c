#include <stdio.h>
#include <console/tty.h> 

void puts(const char* string) 
{
        terminal_writestring(string);

}
