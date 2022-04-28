#include "s21_string.h"

char *s21_strcat(char *dest, const char *src)
{
	int i = 0;
	int j = 0;

	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return dest;
}

int main(){
	// char *str = "kek";
	char str[80] = "a";
	char kek[2] = "s";
	// char *str2 = "mem";
	s21_strcat(str, kek);
	printf("%s\n", str);
	return 0;
}