#include "s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
    char *dst = s21_NULL;
    char *s;
    s21_size_t i;

    i = 0;
    dst = (char *)dest;
    s = (char *)src;
    if (!n)
        dst = s21_NULL;
    if (dst < s) {
        while (i < n) {
            dst[i] = s[i];
            i++;
        }
        } else {
        while (n--)
            dst[n] = s[n];
    }
    return dst;
}

