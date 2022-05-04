#include "s21_string.h"
// %[%][width][.precision][size]type, flags can be placed in any order << ORDER
int is_digit(int c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
} // В ОТДЕЛЬНЫЙ ФАЙЛ фё

char *s21_strcat(char *dest, const char *src)
{
	int i = 0;
	int j = 0;

	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return dest;
}

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
    *len += strlen + 1;
    tmp[strlen + 1] = '\0';
    i = 0;
    for (; buf[i]; i++, strlen--)
    {
        tmp[i] = buf[strlen];
    }
    s21_strcat(str, tmp);
    // buf = tmp;
    // *str = *tmp;
    // printf("%s\n", tmp);
}

void processing(char *str, const char *format, int *len, va_list argp, int *i)
{
    // printf("%c\n", *str);
    // printf("%c\n", *format);
    (*i)++;
    // (*len)++;
    if (*(format + *i) == '%')
    {
        str[*len] = *(format + *i);
        (*len)++;
        return;
    }
    while (is_flag(*(format + *i)) == 0)
    {
        (*i)++;
        if (is_digit(format[*i]))
            
        // if (*format == '.')
        //     // PRECISION
        // if (*format )
        //     // FLAG
        // if (*format)
        //     // SPECIFIER
    }

    if (*(format + *i) == 'c')
    {
        str[*len] = (char)va_arg(argp, int);
        (*len)++;
        // (*i)++;
    }
    if (*(format + *i) == 'd')
    {
        int digit = 0;
        digit = va_arg(argp, int);
        strd(str, digit, len);
    }
    if (*(format + *i) == 's')
    {
        char *tmp = va_arg(argp, char *);
        *len += s21_strlen(tmp);
        s21_strcat(str, tmp);
    }
    // (*i)++;
}

int s21_sprintf(char *str,  char *format, ...)
{
    int len = 0;
    va_list argp;
    va_start(argp, format);
    // for (int i = 0; format[i], i++;)
    // while (format[len])
    for (int i = 0; format[i]; i++)
    {
        if (format[i] == '%')
        {
            // printf("%d\n\n", len);
            processing(str, format, &len, argp, &i);
            continue;
            // i++;
            // *str = *(str + (len - old_len));
            // str++;
            // printf("%d\n", len);
        }
        // else
        // *str = *(format + len);
        // str++;
        str[len] = format[i];
        len++;
    }
    str[len + 1] = '\0';
    va_end(argp);
    return len;
}

int main()
{
    char str[100] = {};
    char a = 'Q';
    int b = 321001;
    int res = 0;
    res = s21_sprintf(str, "hello %d%c ABAB %% ABAB%s\n", b, a, "boobies");
    printf("%s%d\n", str, res);
    return 0;
}
