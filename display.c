#include<types.h>
#include<io.h>

/* Rudimentary write, will be replaced */

void printk_early(int color, const char *string)
{
    volatile uint8_t *video = (volatile uint8_t *)VGABASEADDR;

    while( *string != 0 )
    {
        *video++ = *string++;
        *video++ = color;
    }
}
