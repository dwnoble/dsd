// Common utility functions

#include "common.h"
#include "string.h"

// Copies n bytes from src to dest.  Returns dest.
void *memcpy(void *dest, void *src, size_t n){
	size_t i;
	for(i = 0; i < n; ++i) {
		((u8int*)dest)[i] = ((u8int*)src)[i];
	}
	return dest;
}

// Sets first 'n' bytes of 'dest' to 'value'
void *memset(void *dest, int value, size_t n){
	size_t i;
	for(i = 0; i < n; ++i) {
		*(u8int*)(dest+i) = (u8int)value;
	}
}