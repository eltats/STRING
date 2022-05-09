#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
    char *last_pos = s21_NULL;
    s21_size_t i = 0;
    while (str[i] != '\0') {
        if (str[i] == c)
            last_pos = (char *)str[i];
        ++i;
    }
    return last_pos;
}
