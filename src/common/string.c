// Common utility functions

#include "common.h"
#include "string.h"

// Copies n bytes from src to dest.  Returns dest.
void *memcpy(void *dest, void *src, u32int n){
	u32int i;
	for(i = 0; i < n; ++i) {
		((u32int*)dest)[i] = ((u32int*)src)[i];
	}
	return dest;
}