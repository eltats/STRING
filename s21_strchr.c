#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
    while (*str && *str != (char)c)
        str++;
    return ((char *)str);
}
