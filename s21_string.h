#ifndef S21_STRING_H_
#define S21_STRING_H_
#include <stdarg.h>
#define s21_size_t unsigned long long
#define s21_NULL ((void *)0)
typedef struct s_flags {
    int width;
    short int fminus;
    short int fplus;
    short int fspace;
    short int fh;
    short int fl;
    int precision;
    short int pr;
}           t_flags;

int is_digit(int c);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
int s21_sprintf(char *str,  char *format, ...);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strpbrk(const char *str1, const char *str2);
s21_size_t s21_strspn(const char *str1, const char *str2);
char *s21_strtok(char *str, const char *denim);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);

#endif  // S21_STRING_H_
