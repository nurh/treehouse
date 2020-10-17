.section .data

# The following allocates space for the pointer we will supply the lgdt command with
#
#	|LIMIT|----BASE----|  
#
# LIMIT goes into the halfword, BASE goes into the word.

.global set_gdt
.global reload_segments

gdtr:
.hword	0x0
.word	0x0

.section .text

set_gdt:
	mov 4(%esp), %eax
	movl %eax, gdtr+2
	movw 8(%esp), %ax
	movw %ax, gdtr
	lgdt gdtr
	ret

reload_segments:
	ljmp $0x8, $reload_cs

reload_cs:
	mov $0x10, %ax
	mov %ax, %ds
	mov %ax, %es
	mov %ax, %fs
	mov %ax, %gs
	mov %ax, %ss
	ret
