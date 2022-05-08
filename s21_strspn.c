#include "s21_string.h"

s21_size_t s21_strspn(const char *str1, const char *str2) {
    s21_size_t res = 0;
    while (str1[res] && str1[res] == str2[res])
        res++;
    return res;
}
