#ifndef __STDARG_H
#define __STGARG_H
#include <stdarg.h>
#include <types.h>
#include <display.h>
#endif /* __STDARG_H */


void put_char(char c)
{
	op_putc((uint8_t)c);
}

void put_int(int x)
{
	char out[10]; /* 10 digits should be enough to store a 32 bit val */
	size_t i = 0;

	if(x==0) {
		put_char('0');
		return;
	}

	if(x<0) {
		x = x *-1;
		put_char('-');
	}

	while(x>0) {
		out[i] =(char) ((x % 10)+48);
		i++;
		x = x / 10;
	}

	for(;i>=1;--i) {
		put_char(out[i-1]);
	}
}


void put_hex(int x)
{
	char out[8]; /* 8 digits should be enough to store a 32 bit val */
	int y;
	size_t i = 0;

	if(x==0) {
		put_char('0');
		return;
	}

	if(x<0) {
		x = x *-1;
		put_char('-');
	}

	while(x>0) {		
		y = x % 16;
		if(y < 10) {
			out[i] = (char)y + 48;
		} else {
			out[i] = (char)y + 55;
		}
		
		i++;
		x = x / 16;
	}

	for(;i>=1;--i) {
		put_char(out[i-1]);
	}
}



void put_string(char * s)
{
	size_t i;

	for(i=0; s[i]; i++) {
		op_putc((uint8_t)s[i]);
	}
}

void printk(const char * fmt, ...)
{
	va_list args;
	size_t i;
	unsigned int ignore_next_char = 0;
	uint32_t x;
	char * s;

	va_start(args, fmt);

	for(i = 0; fmt[i]; fmt++) {
		if(fmt[i]=='\\' && fmt[i+1]=='n') {
			put_char('\n');
			fmt++;
			continue;
		} else if(fmt[i]!='%' && ignore_next_char==0) {
			put_char(fmt[i]);
		} else if (ignore_next_char==1) {
			ignore_next_char = 0;
			continue;
		} else {
			ignore_next_char = 1;
			switch(fmt[i+1]) {
				case '%':
					put_char('%');
					break;
				case 'i':
				case 'd':
					x = va_arg(args, int);
					put_int(x);
					break;
				case 'c':
					x = va_arg(args, int);
					put_char(x);
					break;
				case 'x':
					x = va_arg(args, unsigned int);
					put_hex(x);
					break;
				case 's':
					s = va_arg(args, char*);
					put_string(s);
					break;
				default:
					break;
			}
		}
	}

	va_end(args);
}
