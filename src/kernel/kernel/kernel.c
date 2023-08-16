
#include <kernel/tty.h>
#include <stdio.h>

void kernel_init()
{
        terminal_initialize();
}







void kernel_main(void) 
{
        kernel_init();
        
        
        unsigned char str[4] = "";

        terminal_writestring(itoa(5, str, 0));
        
        
        
        


}
