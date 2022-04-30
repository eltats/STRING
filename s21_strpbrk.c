#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2)
{
	int i = 0;
	int j = 0;
	while (*str1)
	{
		i = 0;
		while (str2[i])
		{
			if (*str1 == str2[i])
				return (char *)str1;
		i++;
		}
		str1++;
	}
	return NULL;
}

int main(void)
{
char *p;
p = strpbrk ("this is a test", "this");
printf(p);
return 0;
}