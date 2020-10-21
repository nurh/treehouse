CC:=i686-elf-gcc
AS:=i686-elf-as
LDFLAGS:=-ffreestanding -O2 -nostdlib
CFLAGS:=-std=gnu99 -ffreestanding -O2 -Wall -Wextra
LIBS:=-lgcc
INCLUDE:=include

all: treehouse.bin

treehouse.bin: link.ld boot.o display.o main.o string.o printk.o cpu.o panic.o gdt.o idt.o
	$(CC) -T link.ld -o treehouse.bin $(LDFLAGS) boot.o main.o display.o string.o printk.o cpu.o panic.o gdt.o idt.o $(LIBS)

panic.o: panic.c
	$(CC) -c panic.c -o panic.o  $(CFLAGS) -I$(INCLUDE)

cpu.o: cpu.c
	$(CC) -c cpu.c -o cpu.o  $(CFLAGS) -I$(INCLUDE)

display.o: drivers/display.c
	$(CC) -c drivers/display.c -o display.o $(CFLAGS) -I $(INCLUDE)

main.o: main.c
	$(CC) -c main.c -o main.o $(CFLAGS) -I $(INCLUDE)

printk.o: util/printk.c
	$(CC) -c util/printk.c -o printk.o $(CFLAGS) -I $(INCLUDE)

string.o: util/string.c
	$(CC) -c util/string.c -o string.o $(CFLAGS) -I $(INCLUDE)

gdt.o: gdt.S
	$(AS) -c gdt.S -o gdt.o

idt.o: idt.S
	$(AS) -c idt.S -o idt.o

boot.o: boot/boot.S
	$(AS) -c boot/boot.S -o boot.o

clean:
	rm -f *.o *.bin
