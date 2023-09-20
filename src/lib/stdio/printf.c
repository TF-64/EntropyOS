#include <stdio.h>
#include <stdarg.h>
#include <console/tty.h>
#include <stdbool.h>


char *convert(unsigned int num, int base); 

void slash_processing(char *traverse)
{

        /*
                
        TODO:   \r (carriage return)
                \f (formfeed page break)
                        
                \a (beep sound; needs a sound system -_- )
                        

        */



        switch(*traverse) {
        
        case '\n':
                terminal_nextrow();
                break;

        case '\b':
                terminal_addcol(-1);
                putchar(' ');
                terminal_addcol(-1);
                break; 
        
        case '\t':
                puts("    ");
                break;

        case '\v':
                terminal_addrow_raw(1);
                break;
        
        case '\r':
                
                for(int i = 0; i < terminal_getcolumn(); i++) {
                        printf("\b");
                }
                        
                break;






        default:
                putchar(*traverse);
        }
        





}


void printf(char *format, ...) 
{ 
        char *traverse; 
        unsigned int i; 
        char *s; 

        va_list arg; 
        va_start(arg, format); 

        for(traverse = format; *traverse != '\0'; traverse++)  { 
                while(*traverse != '%') {
                        
                        //printing & processing slash symbols (e.g. \n, \b)
                        
                        slash_processing(traverse);

                        if(*(traverse+1) == '\0') 
                                break;

                        traverse++;
                }
                                

                traverse++;

                if(*traverse == '\0')
                        break;
                
                  
                switch(*traverse) { 
                case 'c':
                        i = va_arg(arg,int);
                        putchar(i);
                        break; 

                case 'd':
                        i = va_arg(arg,int);
                        if(i < 0) { 
                                i = -i;
                                putchar('-'); 
                        } 
                        puts(convert(i,10));
                        break; 

                case 'o':
                        i = va_arg(arg,unsigned int);
                        puts(convert(i,8));
                        break; 

                case 's':
                        s = va_arg(arg,char *);
                        puts(s); 
                        break; 

                case 'x':
                        i = va_arg(arg,unsigned int);
                        puts(convert(i,16));
                        break; 
                }

                //if(*(traverse-1) == '\\')
                //        puts("CAUGHT!!!");
                va_end(arg); 
        } 
}

char *convert(unsigned int num, int base) 
{ 
        static char Representation[]= "0123456789ABCDEF";
        static char buffer[50]; 
        char *ptr; 

        ptr = &buffer[49]; 
        *ptr = '\0'; 

        do { 
                *--ptr = Representation[num%base]; 
                num /= base; 
        } while(num != 0); 

    return(ptr); 
}






