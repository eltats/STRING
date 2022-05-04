#include "s21_string.h"
// %[%][width][.precision][size]type, flags can be placed in any order << ORDER
int is_digit(int c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
} // В ОТДЕЛЬНЫЙ ФАЙЛ фё

int is_flag(int c)
{
    if (c == 'c' || c == 'd' || c == 'i' || c == 'f' || c == 's' || c == 'u')
        return 1;
    return 0;
}
int s21_strlen(char *str)
{
    int res = 0;
    while (str[res])
        res++;
    return res;
}

// char *reversestr(char *buf)
// {
//     char tmp[256] = {};
//     int len = s21_strlen(buf) - 1;
//     for (int i = 0; buf[i]; i++, len--)
//     {
//         tmp[i] = buf[len];
//     }
//     // buf = tmp;
//     return tmp;
// }

void strd(char *str, int digit, int *len)
{
    char buf[256] = {0};
    char tmp[256] = {0};
    int i = 0;
    for (; digit > 0; i++)
    {
        buf[i] = digit % 10 + '0';
        digit /= 10;
    }
    buf[i] = '\0';
    int strlen = s21_strlen(buf) - 1;
    for (int i = 0; buf[i]; i++, strlen--)
    {
        tmp[i] = buf[strlen];
    }
    // buf = tmp;
    *str = tmp;
    // printf("%s\n", tmp);
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
    if (*(format + *len) == 'd')
    {
        int digit = 0;
        digit = va_arg(argp, int);
        strd(str, digit, len);
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
    int b = 321001;
    s21_sprintf(str, "%d\n", b);
    printf("%s", str);
    return 0;
}