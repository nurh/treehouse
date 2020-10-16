struct gdt_entry_struct {
	uint16_t seg_limit_low;
	uint16_t base_addr_low;
	uint8_t base_addr_mid;
	uint8_t access;
	uint8_t flags_limit_high;
	uint8_t base_addr_high;
}__attribute__((packed));

typedef struct gdt_entry_struct gdt_entry_t;

void build_gdt_entry(gdt_entry_t * entry, const uint32_t base, const uint32_t limit, const uint8_t access, const uint8_t flags);
extern void set_gdt(void * gdt, uint16_t size);

#define G_4K_SEGMENTS 0x08
#define DB_32BIT_DEFAULT 0x04

#define P_SEGMENT_PRESENT 0x80
#define DPL_RING_ZERO 0x00
#define S_CODE_OR_DATA_SEGMENT 0x10

#define TYPE_DATA_READ_WRITE 0x02
#define TYPE_CODE_EXECUTE_READ 0x0A
