#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
    s21_size_t i = 0;
    s21_size_t j = 0;

    while (dest[i])
        i++;
    while (src[j] && j < n) {
        dest[i + j] = src[j];
        j++;
    }
    dest[i + j] = '\0';
    return dest;
}
