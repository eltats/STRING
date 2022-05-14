#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
    s21_size_t res = 0;
    int flag = 0;

    for (res = 0; str1[res] && !flag; res++) {
        for (s21_size_t j = 0; str2[j] && !flag; j++) {
            if (str1[res] == str2[j]) {
                flag = 1;
                res--;
            }
        }
    }
    return res;
}
