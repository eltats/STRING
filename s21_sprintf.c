#include "s21_string.h"
// %[%][width][.precision][size]type, flags can be placed in any order << ORDER
// КАКИЕ_ТО ФУНКЦИИ ИСПОЛЬЗОВАНЫ ИЗ СТРИНГ Х/ ВЗЯТЬ НАШИ КОГДА БУДУТ ВСЕ 20 ФУНКЦИЙ
// СВОИ НУЛЛ И САЙЗ Т
int is_digit(int c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
} // В ОТДЕЛЬНЫЙ ФАЙЛ фё

char *s21_strncat(char *dest, const char *src, size_t n)
{
	int i = 0;
	int j = 0;

	while (dest[i])
		i++;
	while (src[j] && j < n)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return dest;
}

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
int intlen(long a)
{
    int i = 0;
    if (a < 0)
        a *= -1;
    // while (a / 10)
    if (a == 0)
        return 1;
    for (; a > 0; i++)
        a /= 10;
    return i;
}

void strd(char *str, long digit, int *len, t_flags fl)
{
    char buf[256] = {0};
    char tmp[256] = {0};
    int i = 0;
    int j = 0;
    long int numlen = intlen(digit);
    // int dd = digit;
    if (fl.precision > numlen)
    {
        fl.precision -= numlen;
        int prec = fl.precision;
        for (; prec >= 0; prec--, j++)
            buf[numlen + prec - 1] = '0';
    }
    if ((fl.fspace || fl.fplus) && digit >= 0)
    {
        if (fl.fplus)
            buf[numlen + fl.precision] = '+';
        else
            buf[numlen + fl.precision] = ' ';
        // (*len)++;
        j++;
    }
    if (digit <= 0)
    {
        if (digit == 0)
        {
            buf[i] = '0';
            i++;
        }
        else
        {
            digit *= -1;
            buf[numlen + fl.precision] = '-';
            j++;
        }
    }
    for (; digit > 0; i++)
    {
        buf[i] = digit % 10 + '0';
        digit /= 10;
    }
    buf[i + j] = '\0';
    int strlen = s21_strlen(buf) - 1;
    if (fl.width)
    {
        fl.width -= (strlen + 1);
        if (!fl.fminus)
            for (; fl.width > 0; fl.width--, (*len)++)
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
    if (fl.width && fl.fminus)
        for (; fl.width > 0; fl.width--, (*len)++)
            str[*len] = ' ';
}

void strf(char *str, double fdigit, int *len, t_flags fl)
{
    char buf[256] = {0};
    char btmp[256] = {0};
    int i = 0;
    long int tmp = 0;
    long int numlen = 0;
    if (!fl.precision)
        fl.precision = 6;
    tmp = (int)fdigit;
    fdigit -= (int)fdigit;
    numlen = intlen(tmp);
    if (tmp >= 0 && (fl.fplus || fl.fspace))
    {
        if (fl.fplus)
            buf[numlen] = '+';
        else
            buf[numlen] = ' ';
    }
    if (tmp < 0)
    {
        buf[numlen] = '-';
        tmp *= -1;
        fdigit *= -1;
    }
    if (tmp == 0)
        buf[i] = '0';
    for (; tmp > 0; i++)
    {
        buf[i] = tmp % 10 + '0';
        tmp /= 10;
    }
    int strlen = s21_strlen(buf) - 1;
    i = 0;
    for (; buf[i]; i++, strlen--)
        btmp[i] = buf[strlen];
    tmp = 0;
    strlen = s21_strlen(btmp);
    btmp[strlen] = '.';
    strlen++;
    for (; fl.precision; fl.precision--, strlen++)
    {
        fdigit *= 10;
        tmp = (int)fdigit;
        btmp[strlen] = tmp % 10 + '0';
        fdigit -= (int)fdigit;
    }
    fl.width -= strlen;
    if (fl.width > 0 && !fl.fminus)
        for (; fl.width; fl.width--, (*len)++)
            str[*len] = ' ';
    s21_strcat(str, btmp);
    *len += s21_strlen(btmp);
    if (fl.width > 0 && fl.fminus)
        for (; fl.width; fl.width--, (*len)++)
            str[*len] = ' ';
}

void processing(char *str, const char *format, int *len, va_list argp, int *i)
{
    t_flags fl = {};
    fl.width = 0;
    fl.fminus = 0;
    fl.fplus = 0;
    fl.precision = 0;
    fl.fspace = 0;
    fl.fh = 0;
    fl.fl = 0;
    (*i)++;
    while (is_flag(format[*i]) == 0)
    {
        if (format[*i] == 'h')
            fl.fh = 1;
        if (format[*i] == 'l')
            fl.fl = 1;
        if (format[*i] == '.')
        {
            (*i)++;
            for (; is_digit(format[*i]); (*i)++)
                fl.precision = (fl.precision * 10) + (format[*i] - '0');
            continue;
        }
        if (format[*i] == '-')
            fl.fminus = 1;
        if (format[*i] == '+')
            fl.fplus = 1;
        if (format[*i] == ' ')
            fl.fspace = 1;
        if (is_digit(format[*i]))
        {
            while (is_digit(format[*i]))
            {
                    fl.width = (fl.width * 10) + (format[*i] - '0');  
                    (*i)++;
            }
        }
        else
            (*i)++;
    }
    if (fl.fplus && fl.fspace)
        fl.fspace = 0;
    if (*(format + *i) == '%' || *(format + *i) == 'c')
    {
        if (fl.width && fl.fminus == 1)
        {
            if (*(format + *i) == '%')
                str[*len] = *(format + *i);
            else
                str[*len] = (char)va_arg(argp, int);
            (*len)++;
            for (int j = 0; j < fl.width - 1; j++, (*len)++)
                str[*len] = ' ';
        }
        else 
        {
        if (fl.width && !fl.fminus)
            for (int j = 0; j < fl.width - 1; j++, (*len)++)
                str[*len] = ' ';
        if (*(format + *i) == '%')
            str[*len] = *(format + *i);
        else
            str[*len] = (char)va_arg(argp, int);
        (*len)++;
        }
    }
    if (*(format + *i) == 'd')
    {
        int res = 0;
        long digit = 0;
        if (fl.fh)
        {
            short int res = (short)va_arg(argp, int);
            digit = res;
        }
        if (fl.fl)
        {
            long res = (long int)va_arg(argp, long int);
            digit = res;
        }
        else if (!fl.fl && !fl.fh)
        {
            int res = va_arg(argp, int);
            digit = res;
        }
        if (digit == 0 && fl.precision )
        strd(str, digit, len, fl);
    }
    if (*(format + *i) == 's')
    {
        char *tmp = va_arg(argp, char *);
        if (fl.precision >= s21_strlen(tmp) || fl.precision == 0)
            fl.precision = s21_strlen(tmp);
        fl.width -= fl.precision;
        if (fl.width <= 0)
            fl.fminus = 0;
        if (fl.width > 0 && fl.fminus)
        {
            s21_strncat(str, tmp, fl.precision);
            *len += fl.precision;
        }
        for (; fl.width > 0; fl.width--, (*len)++)
            str[*len] = ' ';
        if (!fl.fminus)
        {
            s21_strncat(str, tmp, fl.precision);
            *len += fl.precision;
        }
    }
    if (*(format + *i) == 'f')
    {
        double fdigit = va_arg(argp, double);
        strf(str, fdigit, len, fl);
    }
}

int s21_sprintf(char *str,  char *format, ...)
{
    int len = 0;
    va_list argp;
    va_start(argp, format);
    for (int i = 0; format[i]; i++)
    {
        if (format[i] == '%')
        {
            processing(str, format, &len, argp, &i);
            continue;
        }
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
    int b = 0;
    char *format = "%d\n";
    char *ex = "HIBITCHES";
    int res = 0;
    res = s21_sprintf(str, format,  b);
    printf("%s%d\n", str, res);
    res = sprintf(str, format, b);
    printf("%s%d\n", str, res);
    return 0;
}
