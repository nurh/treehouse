# Boot.S taken mostly from the OSDEV wiki.

# Constants for the multiboot header
.set MULTIBOOT_ALIGN,    1<<0            
.set MULTIBOOT_MEMINFO,  1<<1           
.set MULTIBOOT_MAGIC,    0x1BADB002       
.set MULTIBOOT_FLAGS,    MULTIBOOT_ALIGN | MULTIBOOT_MEMINFO  
.set MULTIBOOT_CHECKSUM, -(MULTIBOOT_MAGIC + MULTIBOOT_FLAGS)

# The multiboot header
.section .multiboot
.global _multiboot

.align 4
.long MULTIBOOT_MAGIC
.long MULTIBOOT_FLAGS
.long MULTIBOOT_CHECKSUM

.section .bootstrap_stack, "aw", @nobits
stack_bottom:
.skip 16384 # 16 KiB
stack_top:

.section .text
.global _start
.type _start, @function
_start:
	cli
	hlt

.failsafeloop:
	jmp .failsafeloop

.size _start, . - _start
