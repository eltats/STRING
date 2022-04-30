#include "s21_string.h"

char *s21_strchr(const char *str, int c)
{
	while (*str && *str != (char)c)
		str++;
	return ((char *)str);
}

// int main(){
// 	char *str = "lobe";
// 	printf("%s\n", s21_strchr(str, (int)'b'));
// 	return 0;
// }