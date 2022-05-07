#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

typedef struct s_flags 
{
	int width;
	short int fminus;
	short int fplus;
	short int fspace;
	short int fh;
	short int fl;
	int precision;
	short int pr;
}			t_flags;
int s21_memcmp(const void *str1, const void *str2, size_t n);
int is_digit(int c);
char *s21_strcat(char *dest, const char *src);