#include "s21_string.h"

void *s21_memmove(void *dest, const void *src, size_t n)
{
	char *dst;
	char *s;
	size_t i;

	i = 0;
	dst = (char *)dest;
	s = (char *)src;
	if (!n)
		return 0;
	if (dst < s)
		while (i < n)
		{
			dst[i] = s[i];
			i++;
		}
	else
	{
		while (n--)
			dst[n] = s[n];
	}
	return dst;
}

