#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
    s21_size_t needle_len = strlen(needle);
    s21_size_t haystack_len = strlen(haystack);
    char *ret = s21_NULL;
    for (s21_size_t i = 0; i < haystack_len; ++i) {
        if (s21_strncmp(haystack[i], needle, needle_len) != 0) {
            ret = haystack[i];
            break;
        }
    }
    return ret;
}
