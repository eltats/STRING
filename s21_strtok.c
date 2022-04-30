#include "s21_string.h"


#include <string.h>
#include <stdio.h>

char *s21_strtok(char *str, const char *denim) {
	static char *static_str;
	int cut = 0;
	char *res = NULL;
	int buf[256] = {0};
	if (!denim || !str)
		return NULL;
	if (static_str)
		str = static_str;
	for (int i = 0; denim[i]; i++)
		buf[(int)denim[i]]++;
	for (int i = 0; str[i]; i++)
	{
		if (!res)
			res = &str[i];
		if (buf[(int)str[i]] > 0 && !cut){
			// static_str = &str[i];
			cut = 1;
			str[i] = '\0';
			i++;
			while (str[i] && buf[(int)str[i]])
				i++;
			// i++;
			static_str = &str[i];
		}
	}
	if (!res)
		return NULL;
	if (*res == '\0')
		return NULL;
	return res;
}
int main () {
   char str[80] = "this is world";
   const char s[2] = " ";
   char *token;
   
   /* get the first token */
   token = s21_strtok(str, s);
    token = s21_strtok(str, s);
	    token = s21_strtok(str, s);
   printf( "TOKEN = %s\n", token );
   /* walk through other tokens */
//    while( token != NULL ) {
//       printf( " %s\n", token );

//       token = s21_strtok(NULL, s);
//    }
   
   return(0);
}