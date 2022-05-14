#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
    void *ptr = s21_NULL;
    int flag = 0;
    s21_size_t res = -1;
    for (s21_size_t i = 0; i < n && !flag; i++) {
        if (*((char *)str + i) == (char)c) {
            res = i;
            flag = 1;
        }
        --n;
    }
    if ((int)res != -1)
        ptr = (void *)str + res;
    return ptr;
}

// int main(){
//       char src1[15] = "1234567890";
//   char src2[3] = {'\0', '\0', '\0'};
//   char src3[0];
//   void *res1, *res2;

//   res1 = s21_memchr(src1, '4', 10);
//   res2 = memchr(src1, '4', 10);
//   printf("%p\n%p\n\n", res1, res2);

//   res1 = s21_memchr(src2, '\0', 2);
//   res2 = memchr(src2, '\0', 2);
//   printf("%p\n%p\n\n", res1, res2);

//   res1 = s21_memchr(src3, 'w', 10);
//   res2 = memchr(src3, 'w', 10);
//   printf("%p\n%p\n\n", res1, res2);
// }