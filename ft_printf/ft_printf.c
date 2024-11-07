
//ekw

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>


int ft_strlen(char *str)
{
    int i;

    i = 0;
    if (str == 0)
        return(0);
    while(str[i])
        i++;
    return(i);
}


void ft_putstr(char *str, int *len)
{
    if (str == 0)
        str = "(null)";
    *len += write(1, str, ft_strlen(str));
}

static void	ft_putdigit(long int num, int base, int *len)
{
	char *hexa;

	hexa = "0123456789abcdef";

	if (num < 0)
	{
		num = -num;
		*len += write(1, "-", 1);
	}
	if (num >= base)
		ft_putdigit((num / base), base, len);
	*len += write(1, &hexa[num % base], 1);


}


void special(va_list arg, char *fmt, int *len)
{
    if (*fmt == '%')
        ft_putstr("%", len);
    else if (*fmt == 's')
        ft_putstr(va_arg(arg, char *), len);
	else if (*fmt == 'd')
		ft_putdigit(va_arg(arg, long int), 10, len);
	else if (*fmt == 'x')
		ft_putdigit(va_arg(arg, unsigned int), 16, len);
}

int ft_printf(char *fmt, ...)
{
    va_list     arg;
    int         len;

    len = 0;
    va_start(arg, fmt);
    while(*fmt)
    {
        if((*fmt == '%') && *(fmt + 1))
        {
            fmt++;
            special(arg, fmt, &len); 
        }
        else
            len += write(1, fmt, 1);
        fmt++;
    }
    va_end(arg);
    return (len);
}



int main(int ac, char av)
{

	ft_printf("%s je t aime, -2147483648 en hexa : %x\n", "Papa", 31);

}


