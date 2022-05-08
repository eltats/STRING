#include "s21_string.h"

int is_digit(int c) {
    int ret = 0;
    if (c >= '0' && c <= '9')
        ret = 1;
    return ret;
}
