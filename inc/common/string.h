#ifndef STRING_H
#define STRING_H

// Copies n bytes from src to dest.  Returns dest or null if error.
void *memcpy(void *dest, void *src, size_t n);
// Sets first 'n' bytes of 'dest' to 'value'
void *memset(void *dest, int value, size_t n);

#endif