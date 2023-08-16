
#include <kernel/mmanager.h>
#include <console/tty.h>

void kernel_init()
{
        terminal_init();
        terminal_writestring("kernel init ");        

}




