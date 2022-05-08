#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    int ret = 0;
    while (n > 1 && *(char *)str1 == *(char *)str2) {
        str1 = (char *)str1 + 1;
        str2 = (char *)str2 + 1;
        n--;
    }
    if (*(char *)str1 != *(char *)str2)
        ret = 1;
    // return *((unsigned char *)str1) - *((unsigned char *)str2);
    return 0;
}
