#include <types.h>
#include <cpu.h>
#include <string.h>

/*
 * Intel's GDT has some pretty weird splits.
 *
 * Word 0:
 * 	Bit 0-15 : Segment limit 00 to 15
 * 	Bit 16-31 : Base address 00 to 15
 * Word 1:
 * 	Bit 0-7: Base address 16 to 23
 *	Bit 8-11: Type
 *	Bit 12: S
 *	Bit 13-14: DPL
 *	Bit 15: P
 *	Bit 16-19: Segment limit 16-19
 *	Bit 20: AVL
 *	Bit 21: L
 *	Bit 22: D/B
 *	Bit 23: G
 *	Bit 24-41: Base address 24-31
 */

void build_gdt_entry(gdt_entry_t * entry, const uint32_t base, const uint32_t limit, const uint8_t access, const uint8_t flags)
{
	entry->seg_limit_low = limit & 0xFFFF;
	entry->base_addr_low = base & 0xFFFF;
	entry->base_addr_mid = (base >> 16) & 0x00FF;
	entry->access = access;
	entry->flags_limit_high = (flags << 4) | ((limit >> 16) & 0x000F);
	entry->base_addr_high = (base >> 24) & 0x00FF;
}

void init_gdt(void)
{

	build_gdt_entry(&gdt[0], 0x0, 0x0, 0x0, 0x0);
	build_gdt_entry(&gdt[1], 0x0, 0xFFFFFFFF, (P_SEGMENT_PRESENT | DPL_RING_ZERO | S_CODE_OR_DATA_SEGMENT | TYPE_CODE_EXECUTE_READ), (G_4K_SEGMENTS | DB_32BIT_DEFAULT));
	build_gdt_entry(&gdt[2], 0x0, 0xFFFFFFFF, (P_SEGMENT_PRESENT | DPL_RING_ZERO | S_CODE_OR_DATA_SEGMENT | TYPE_DATA_READ_WRITE), (G_4K_SEGMENTS | DB_32BIT_DEFAULT));

	set_gdt((void *)gdt, sizeof(gdt));
}

void init_idt(void)
{
	memset((void *)idt, 0, sizeof(idt));
	set_idt((void *)idt, sizeof(idt)-1);
}
