#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
 
#include <console/tty.h> 
#include <console/vga.h>
 
static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
static uint16_t* const VGA_MEMORY = (uint16_t*) 0xB8000;
 
static size_t terminal_row;
static size_t terminal_column;
static uint8_t terminal_color;
static uint16_t* terminal_buffer;






void terminal_init(void) 
{
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	terminal_buffer = VGA_MEMORY;
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}
 
void terminal_setcolor(uint8_t color) 
{
	terminal_color = color;
}
 
void terminal_putentryat(unsigned char c, uint8_t color, size_t x, size_t y) 	
{
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
}
 
void terminal_scroll(int line) 
{
	int* loop;
        char c;
	for(loop = line * (VGA_WIDTH * 2) + VGA_MEMORY; loop < VGA_WIDTH * 2; loop++) {
                c = *loop;
		*(loop - (VGA_WIDTH * 2)) = c;
	}
}


void terminal_delete_last_line() 
{
	int x, *ptr;
 
	for(x = 0; x < VGA_WIDTH * 2; x++) {
		ptr = VGA_MEMORY + (VGA_WIDTH * 2) * (VGA_HEIGHT - 1) + x;
		*ptr = 0;
	}
}




int terminal_getrow()
{
        return terminal_row;
}

int terminal_getcolumn()
{
        return terminal_column;
}







void terminal_putchar(char c) 
{
	int line;
	unsigned char uc = c;
 
	terminal_putentryat(uc, terminal_color, terminal_column, terminal_row);
	if (++terminal_column == VGA_WIDTH) {
		terminal_column = 0;
		if (++terminal_row == VGA_HEIGHT) {
			for(line = 1; line <= VGA_HEIGHT - 1; line++)
				terminal_scroll(line);
				
			terminal_delete_last_line();
			terminal_row = VGA_HEIGHT - 1;
		}
	}
}
 
void terminal_write(const char* data, size_t size) 
{
	for (size_t i = 0; i < size; i++)
		terminal_putchar(data[i]);
}
 
void terminal_writestring(const char* data) 
{
	terminal_write(data, strlen(data));
}








void terminal_nextrow()
{
        terminal_addrow(1);
}

void terminal_nextcol()
{
        terminal_addcol(1);
}

void terminal_addrow(int n)
{
        terminal_column = -1;
        terminal_row += n;

        terminal_putchar(' ');
}

void terminal_addrow_raw(int n)
{
        terminal_row += n;
}


void terminal_addcol(int n)
{
        terminal_column += n;        
}




