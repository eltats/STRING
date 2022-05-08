#include "s21_string.h"


#include <string.h>
#include <stdio.h>

char *s21_strtok(char *str, const char *denim) {
    static char *static_str;
    int cut = 0;
    char *res = s21_NULL;
    int buf[256] = {0};
    if (!denim || !str)
        res = s21_NULL;
    if (static_str)
        str = static_str;
    for (int i = 0; denim[i]; i++)
        buf[(int)denim[i]]++;
    for (int i = 0; str[i]; i++) {
        if (!res)
            res = &str[i];
        if (buf[(int)str[i]] > 0 && !cut) {
            cut = 1;
            str[i] = '\0';
            i++;
            while (str[i] && buf[(int)str[i]])
                i++;
            static_str = &str[i];
        }
    }
    if (!res)
        res = s21_NULL;
    if (*res == '\0')
        res = s21_NULL;
    return res;
}
