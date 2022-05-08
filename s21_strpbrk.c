#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
    int i = 0;
    int j = 0;
    char *ret = s21_NULL;
    while (*str1) {
        i = 0;
        while (str2[i]) {
            if (*str1 == str2[i]) {
                ret = (char *)str1;
                break;
            }
        i++;
        }
        str1++;
    }
    return ret;
}

