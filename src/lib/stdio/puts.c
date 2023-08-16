#include <stdio.h>
#include <kernel/tty.h> 

void puts(const char* string) 
{
        terminal_writestring(string);

}
