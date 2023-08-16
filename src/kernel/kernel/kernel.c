
#include <kernel/tty.h>
#include <stdio.h>

void kernel_init()
{
        terminal_initialize();
}







void kernel_main(void) 
{
        kernel_init();
        
        
        char str[4];
        int n = 1234;
        itoa(n, str);

        terminal_writestring(str);
        
        
        
        


}
