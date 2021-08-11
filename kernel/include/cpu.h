struct gdt_entry_struct {
	uint16_t seg_limit_low;
	uint16_t base_addr_low;
	uint8_t base_addr_mid;
	uint8_t access;
	uint8_t flags_limit_high;
	uint8_t base_addr_high;
}__attribute__((packed));

struct idt_entry_struct {
	uint16_t offset_lo;
	uint16_t selector;
	uint8_t zero;
	uint8_t type;
	uint16_t offset_hi;
}__attribute__((packed));

struct registers_struct {
	uint32_t ds;
	uint32_t es;
	uint32_t fs;
	uint32_t gs;

	uint32_t edi;
	uint32_t esi;
	uint32_t ebp;
	uint32_t esp;
	uint32_t ebx;
	uint32_t edx;
	uint32_t ecx;
	uint32_t eax;

	uint32_t int_no;
	uint32_t err_code;

	uint32_t eip;
	uint32_t cs;
	uint32_t eflags;
	uint32_t sp;
	uint32_t ss;
}__attribute__((packed));

typedef struct gdt_entry_struct gdt_entry_t;
typedef struct idt_entry_struct idt_entry_t;
typedef struct registers_struct registers_t;

void build_gdt_entry(gdt_entry_t * entry, const uint32_t base, const uint32_t limit, const uint8_t access, const uint8_t flags);
void build_idt_entry(idt_entry_t * entry, const uint32_t offset, const uint16_t selector, const uint8_t type);

void init_gdt(void);
void init_idt(void);
extern void set_gdt(void * gdt, uint16_t size);
extern void reload_segments(void);
extern void set_idt(void * idt, uint16_t size);
extern void isr_wrapper_default(void);
extern void interrupt_0x20_wrapper(void);

extern gdt_entry_t gdt[3];
extern idt_entry_t idt[256];

static inline void disable_interrupts(void)
{
	__asm__("cli");
}

static inline void enable_interrupts(void)
{
	__asm__("sti");
}

#define G_4K_SEGMENTS 0x08
#define DB_32BIT_DEFAULT 0x04

#define P_SEGMENT_PRESENT 0x80
#define DPL_RING_ZERO 0x00
#define S_CODE_OR_DATA_SEGMENT 0x10

#define TYPE_DATA_READ_WRITE 0x02
#define TYPE_CODE_EXECUTE_READ 0x0A
