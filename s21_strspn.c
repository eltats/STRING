#include "s21_string.h"

s21_size_t s21_strspn(const char *str1, const char *str2) {
    s21_size_t ret = 0;
    s21_size_t j = 0;

    for (s21_size_t i = 0; str1[i]; i++, ret++) {
        for (j = 0; str2[j] && str2[j] != str1[i]; j++) {
        }
        if (!str2[j]) break;
    }
    return ret;
}
