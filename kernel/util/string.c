#include <types.h>

void *memset(void *s, int c, size_t n)
{
	size_t i;
	
	uint8_t * mem_ptr = (uint8_t *)s;
	uint8_t mem_val = (uint8_t)(c & 0xff);

	for(i=0;i<n;i++) {
		*mem_ptr = mem_val;
		mem_ptr++;
	}

	return s;
}

void *memcpy(void *dest, const void *src, size_t n)
{
	size_t i;
	uint8_t *dest_prime;
	uint8_t *src_prime;

	dest_prime = (uint8_t *)dest;
	src_prime = (uint8_t *)src;

	for(i=0;i<n;i++) {
		*dest_prime++ = *src_prime++;
	}

	return dest;
}

void *memmove(void *dest, const void *src, size_t n)
{
	uint8_t *dest_prime;
	uint8_t *src_prime;

	size_t i;

	if (src == dest) {
		return dest;
	} else if(dest >= (src+n) || dest < src) {
		return memcpy(dest, src, n);
	} else if((src < dest) && (dest < (src+n))) {
		dest_prime = (uint8_t *)((dest + n) - 1);
		src_prime = (uint8_t *)((src + n) - 1);
		
		for(i=0;i<n;i++) {
			*dest_prime-- = *src_prime--;
		}

		return dest;		
	}

	return dest;
}
