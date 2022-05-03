#include "s21_string.h"
// %[%][width][.precision][size]type, flags can be placed in any order << ORDER

int is_flag(int c)
{
    if (c == 'c' || c == 'd' || c == 'i' || c == 'f' || c == 's' || c == 'u')
        return 1;
    return 0;
}

void processing(char *str, const char *format, int *len, va_list argp)
{
    // printf("%c\n", *str);
    // printf("%c\n", *format);
    (*len)++;
    if (*(format + *len) == '%')
    {
        *str = *(format + *len);
        return;
    }
    while (is_flag(*(format + *len)) == 0)
    {
        (*len)++;
        // if (is_digit(*format))
        //     // WIDTH
        // if (*format == '.')
        //     // PRECISION
        // if (*format )
        //     // FLAG
        // if (*format)
        //     // SPECIFIER
    }

    if (*(format + *len) == 'c')
    {
        *str = (char)va_arg(argp, int);
        (*len)++;
    }
}

int s21_sprintf(char *str,  char *format, ...)
{
    int len = 0;
    va_list argp;
    va_start(argp, format);
    // for (int i = 0; format[i], i++;)
    while (format[len])
    {
        if (format[len] == '%')
        {
            // printf("%d\n\n", len);
            processing(str, format, &len, argp);
            // *str = *(str + (len - old_len));
            str++;
            // printf("%d\n", len);
        }
        // else
        *str = *(format + len);
        str++;
        len++;
    }
    *str = '\0';
    va_end(argp);
    return len;
}

int main()
{
    char str[100] = {};
    char a = 'A';
    sprintf(str, "Hc%%I%c\n", a);
    printf("%s", str);
    return 0;
}