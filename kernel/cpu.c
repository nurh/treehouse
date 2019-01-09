#include <types.h>
#include <cpu.h>

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

void load_gdt(gdt_entry_t * entry, const uint32_t base, const uint32_t limit, const uint8_t access, const uint8_t flags)
{
	entry->seg_limit_low = limit & 0xFFFF;
	entry->base_addr_low = base & 0xFFFF;
	entry->base_addr_mid = (base >> 16) & 0x00FF;
	entry->access = access;
	entry->flags_limit_high = (limit >> 16) & 0x000F;
	entry->flags_limit_high = (flags & 0xFF) | entry->flags_limit_high;
	entry->base_addr_high = base >> 24;
}
