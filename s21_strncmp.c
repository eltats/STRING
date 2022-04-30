#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, size_t n)
{
	// size_t i;
	// if (n + 1 < n)
		// return -1;
	// i = 0;
	while (n--)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return 0;
}

int main()
{
	printf("%d\n", strncmp("hiweq", "hiwed", -1));
	printf("%d\n", s21_strncmp("hiweq", "hiwed", -1));
	return 0;
}