#define PIT_CHAN0_PORT 0x40
#define PIT_CMD_PORT 0x43

void set_pit_count(uint16_t count);
void set_pit_cmd(uint8_t cmd);
