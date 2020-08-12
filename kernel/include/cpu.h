struct gdt_entry_struct {
	uint16_t seg_limit_low;
	uint16_t base_addr_low;
	uint8_t base_addr_mid;
	uint8_t access;
	uint8_t flags_limit_high;
	uint8_t base_addr_high;
}__attribute__((packed));

typedef struct gdt_entry_struct gdt_entry_t;

void build_gdt(gdt_entry_t * entry, const uint32_t base, const uint32_t limit, const uint8_t access, const uint8_t flags);
extern void set_gdt(void * gdt, uint16_t size);
