#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, size_t n)
{
	if (!n)
		return 0;
	while (n > 1 && *(char *)str1 == *(char *)str2)
	{
		str1 = (char *)str1 + 1;
		str2 = (char *)str2 + 1;
		n--;
	}
	if (*(char *)str1 != *(char *)str2)
		return 1;
	// return *((unsigned char *)str1) - *((unsigned char *)str2);
	return 0;
}

int main(){
	// printf("%d     %d\n\n", memcmp("okey", NULL, 3513512516689876545ll), s21_memcmp("okey", NULL, 3513512516689876545ll));
	printf("%d\n\n", memcmp(NULL, "okeg", 3));
	return 0;
}