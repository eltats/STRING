#include "s21_string.h"
// %[%][width][.precision][size]type, flags can be placed in any order << ORDER
int is_digit(int c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

void processing(char *str, const char *format, int *len)
{
    // printf("%c\n", *str);
    // printf("%c\n", *format);
    (*len)++;
    if (*format == '%')
        *str = *(format + *len);
    if (is_digit(*format))
        // WIDTH
    if (*format == '.')
        // PRECISION
    if (*format )
        // FLAG
    if (*format)
        // SPECIFIER
    

}

int s21_sprintf(char *str,  char *format, ...)
{
    int len = 0;
    // for (int i = 0; format[i], i++;)
    while (format[len])
    {
        if (format[len] == '%')
        {
            // printf("%d\n\n", len);
            processing(str, format, &len);
            // *str = *(str + (len - old_len));
            // printf("%d\n", len);
        }
        // else
        *str = *(format + len);
        str++;
        len++;
    }
    *str = '\0';
    return len;
}

int main()
{
    char str[100] = {};
    s21_sprintf(str, "Habc%%I");
    printf("%s\n", str);
    return 0;
}