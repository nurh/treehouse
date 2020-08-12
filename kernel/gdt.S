.section .data

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
