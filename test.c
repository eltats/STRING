#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void change (int *a)
{
	(*a)++;
}

int main(void)
{
	// int a = 10123;
	// char str[80] = {};
	// char *xmp;
	// xmp = (char *)malloc(sizeof(char) * 5);
	// char *p = xmp;
	// // change(&a);'
	// for (int i = 0; a > 0; i++)
	// {

	// 	xmp[i] = (a % 10) + 48;
	// 	a = a / 10;
	// 	// xmp++;
	// }
	// a = a / 10;
	// xmp[3] = (a % 10) + 48;
	// xmp[4] = '\0';
	//  int a = 1234567123;
	// float a = 10.123;
	// char str[80] = {};
	// int tmp = 0;
	// for (int i = 0; i < 6; i++)
	// {
	// 	tmp = (int)a;
	// 	for (int j = i; tmp > 0; j++)
	// 	{
	// 		str[j] = tmp % 10 + '0';
	// 		tmp /= 10;
	// 	}
	// 	a -= (int)a;
	// 	a *= 10;
	// }
	printf("%+f\n", 0.123);
	return 0;
}
