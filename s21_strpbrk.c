#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
    char *ret = s21_NULL;
    char *tmp = (char *)str2;
    while (*str1 && !ret) {
        str2 = tmp;
        while (*str2) {
            if (*str1 == *str2) {
                ret = (char *)str1;
                break;
            }
            str2++;
        }
        str1++;
    }
    return ret;
}

// int main()
// {
//       char str1[7] = "School";
//   char str2[4] = "Hole";
//   char *result, *result2;

//   result = s21_strpbrk(str1, str2);
//   result2 = strpbrk(str1, str2);
//   printf("%s\n%s\n", result, result2);
// }