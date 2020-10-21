.section .data

.global set_idt

idt_ptr:
.hword	0x0
.word	0x0

.section .text

set_idt:
	mov 4(%esp), %eax
	movl %eax, idt_ptr+2
	movw 8(%esp), %ax
	movw %ax, idt_ptr
	lidt idt_ptr
	ret
