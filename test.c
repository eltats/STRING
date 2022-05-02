#include <stdio.h>
#include <string.h>
void change (int *a)
{
	(*a)++;
}

int main(void)
{
	int a = 1;
	change(&a);
	printf("%d\n", a);
	return 0;
}
