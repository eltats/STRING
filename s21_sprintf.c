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
    if (c == 'c' || c == 'd' || c == 'i' || c == 'f' || c == 's' || c == 'u' || c == '%')
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

void strd(char *str, int digit, int *len, int width)
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
    if (width)
    {
        width -= (strlen + 1);
        for (; width > 0; width--, (*len)++)
            str[*len] = ' ';
    }
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
    int width = 0;
    // printf("%c\n", *str);
    // printf("%c\n", *format);
    (*i)++;
    // (*len)++;
    while (is_flag(format[*i]) == 0)
    {
        if (is_digit(format[*i]))
        {
            while (is_digit(format[*i]))
            {
                width = (width * 10) + (format[*i] - '0');  
                (*i)++;
            }
        }
        else
            (*i)++;
        // if (*format == '.')
        //     // PRECISION
        // if (*format )
        //     // FLAG
        // if (*format)
        //     // SPECIFIER
    }
    if (*(format + *i) == '%' || *(format + *i) == 'c')
    {
        if (width)
        {
            for (int j = 0; j < width - 1; j++, (*len)++)
                str[*len] = ' ';
        }
        if (*(format + *i) == '%')
            str[*len] = *(format + *i);
        else
            str[*len] = (char)va_arg(argp, int);
        (*len)++;
    }
    // if (*(format + *i) == 'c')
    // {
    //     str[*len] = (char)va_arg(argp, int);
    //     (*len)++;
    //     // (*i)++;
    // }
    if (*(format + *i) == 'd')
    {
        int digit = 0;
        digit = va_arg(argp, int);
        strd(str, digit, len, width);
    }
    if (*(format + *i) == 's')
    {
        char *tmp = va_arg(argp, char *);
        width -= s21_strlen(tmp);
        while(width--)
        {
            str[*len] = ' ';
            (*len)++;
        }
        s21_strcat(str, tmp);
        *len += s21_strlen(tmp);
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
    res = sprintf(str, "HELLO %-10% %10s%5d  %2c\n", "JOHN", 228, 'K');
    printf("%s%d\n", str, res);
    return 0;
}
