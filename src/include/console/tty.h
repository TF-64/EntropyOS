#ifndef _KERNEL_TTY_H
#define _KERNEL_TTY_H
 
#include <stddef.h>
 
void terminal_init(void);
void terminal_putchar(char c);
void terminal_write(const char* data, size_t size);
void terminal_writestring(const char* data);

int terminal_getrow();
int terminal_getcolumn();

void terminal_nextrow();
void terminal_nextcol();
void terminal_addrow(int n);
void terminal_addrow_raw(int n);
void terminal_addcol(int n);





#endif
