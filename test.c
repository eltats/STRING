#include <stdio.h>
#include <string.h>
int main(void)
{
	char *p;
	p = strpbrk ("this is a test", " absj");
	printf(p);
	return 0;
}
