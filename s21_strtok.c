#include "s21_string.h"


#include <string.h>
#include <stdio.h>
int isdelim(const char *str, char c)
{
    int ret = 0;
    for (int i = 0 ; str[i]; i++) {
        if (str[i] == c) {
            ret = 1;
            break;
        }
    }
    return ret;
}

char *s21_strtok(char *str, const char *delim) {
    static char *static_str;
    char *ret = s21_NULL;
    int flag = 0;
    if (!str)
        str = static_str;
    if (str) {
        for (int i = 0; str[i]; i++) {
            if (isdelim(delim, str[i]) && !flag) {
                str[i] = '\0';
                ret = str;
                i++;
                flag = 1;
                while (str[i] && isdelim(delim, str[i]))
                    i++;
                static_str = &str[i];
                break;
            }
        }
    }
    return ret;
}
// int main(){
//       char str[] = "This isnt bug, this feat.";
//   printf("Разделение строки \"%s\" на лексемы.", str);
//   char *pch = s21_strtok(str," ,."); //во втором параметре указаны разделители (пробел, запятая, точка)
//   printf("\nЛексемы:\n");
//   while (pch != NULL) //пока есть лексемы
//   {
//       printf("\n%s\n", pch);
//       pch = s21_strtok(NULL, " ,.");
//   }
//   return 0;
//   char str[] = "School-21";
//   char *tok1 = s21_strtok(str, "-");
//   char *tok2 = s21_strtok(str, "-");
//   char *tok3 = s21_strtok(str, "");
//   char *tok4 = s21_strtok(str, "");
//   char *tok5 = s21_strtok(str, "oo");
//   char *tok6 = s21_strtok(str, "oo");
//   char *tok7 = s21_strtok(str, "Sc");
//   char *tok8 = s21_strtok(str, "Sc");
//   char *tok9 = s21_strtok(str, "21");
//   char *tok10 = s21_strtok(str, "21");
//   printf("%s  =  %s\n\n", tok1, tok2);
//   printf("%s  =  %s\n\n", tok3, tok4);
//   printf("%s  =  %s\n\n", tok5, tok6);
//   printf("%s  =  %s\n\n", tok7, tok8);
//   printf("%s  =  %s\n\n", tok9, tok10);
//   }