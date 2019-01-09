static inline void halt(void)
{
	__asm__("cli");
	__asm__("hlt");
}

void panic(char * msg);
