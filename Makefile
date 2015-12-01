CC:=i686-elf-gcc
AS:=i686-elf-as
LDFLAGS:=-ffreestanding -O2 -nostdlib
LIBS:=-lgcc

all: treehouse.bin

treehouse.bin: link.ld boot.o
	$(CC) -T link.ld -o treehouse.bin $(LDFLAGS) boot.o $(LIBS)

boot.o: boot.S
	$(AS) -c boot.S -o boot.o

clean:
	rm -f *.o *.bin
