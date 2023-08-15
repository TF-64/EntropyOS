
#include <kernel/tty.h>
#include <stdio.h>


void kernel_init()
{
        terminal_initialize();
}







void kernel_main(void) 
{
        kernel_init();


        terminal_writestring("Hello world");

}
