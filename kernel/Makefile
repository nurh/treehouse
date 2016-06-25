CC:=i686-elf-gcc
AS:=i686-elf-as
LDFLAGS:=-ffreestanding -O2 -nostdlib
CFLAGS:=-std=gnu99 -ffreestanding -O2 -Wall -Wextra
LIBS:=-lgcc
INCLUDE:=include

all: treehouse.bin

treehouse.bin: link.ld boot.o display.o main.o string.o printk.o
	$(CC) -T link.ld -o treehouse.bin $(LDFLAGS) boot.o main.o display.o string.o printk.o $(LIBS)

display.o: display.c
	$(CC) -c display.c -o display.o $(CFLAGS) -I $(INCLUDE)

main.o: main.c
	$(CC) -c main.c -o main.o $(CFLAGS) -I $(INCLUDE)

printk.o: util/printk.c
	$(CC) -c util/printk.c -o printk.o $(CFLAGS) -I $(INCLUDE)

string.o: util/string.c
	$(CC) -c util/string.c -o string.o $(CFLAGS) -I $(INCLUDE)

boot.o: boot.S
	$(AS) -c boot.S -o boot.o

clean:
	rm -f *.o *.bin
