#include "s21_string.h"

int s21_strcmp(const char *str1, const char *str2) {
    s21_size_t i;
    i = 0;
    int ret = 0;
    while (str1[i] != '\0' || str2[i] != '\0') {
        if (*str1 != *str2) {
            ret = (*str1 - *str2);
            break;
        }
        str1++;
        str2++;
    }
    return ret;
}
