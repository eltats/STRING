#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    int ret = 0;
    while (n--) {
        if (*str1 != *str2) {
            ret = (*str1 - *str2);
            break;
        }
        str1++;
        str2++;
    }
    return ret;
}
