
#include <kernel/tty.h>



void kernel_main(void) 
{
	terminal_initialize();
	terminal_writestring("Hello, Entropy!");  
}
