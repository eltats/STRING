#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
    s21_size_t i = 0;
    char *ptr = (char *)str;
    while (i <= n) {
        if (*(ptr++) == (char)c) {
            --ptr;
            break;
        }
        ++i;
    }
    return (void*)ptr;
}
