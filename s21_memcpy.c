#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
    char *ptr_dest = (char *)dest;
    const char *ptr_src = (const char *)src;
    while (n != '\0') {
        *(ptr_dest++) = *(ptr_src++);
        --n;
    }
    return dest;
}
