#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int		ft_printf(const char *format, ...);
void	put_str(char *str, int *lenght);
void	put_nbr(long long int nbr, int base, int *lenght);

int main(void)
{
	char	*str;
	char	*null;
	int		dec;
	int		hex;
	int		hexneg;
	int		printf_lenght;
	int		ft_printf_lenght;

	str = "melvin";
	null = NULL;
	dec = -1024;
	hex = 12;
	hexneg = -1;

	printf_lenght = printf("%s\n", str);
	ft_printf_lenght = ft_printf("%s\n", str);
	printf("\nprintf: %d = ft_printf: %d\n", printf_lenght, ft_printf_lenght);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	pointer;
	int		lenght;

	lenght = 0;
	va_start(pointer, format);
	while (*format)
	{
		if (*format == '%' && (*(format + 1) == 's' || *(format + 1) == 'd' || *(format + 1) == 'x'))
		{
			format++;
			if (*format == 's')
				put_str(va_arg(pointer, char *), &lenght);
			else if (*format == 'd')
				put_nbr((long long int)va_arg(pointer, int), 10, &lenght);
			else if (*format == 'x')
				put_nbr((long long int)va_arg(pointer, unsigned int), 16, &lenght);
		}
		else
			lenght += write(1, format, 1);
		format++;
	}
	return(va_end(pointer), lenght);
}

void	put_str(char *str, int *lenght)
{
	if (!str)
		str = "(null)";
	while (*str)
		*lenght += write(1, str++, 1);
}

void	put_nbr(long long int nbr, int base, int *lenght)
{
	char *hexadec;

	hexadec = "0123456789abcdef";
	if (nbr < 0)
	{
		nbr *= -1;
		*lenght += write(1, "-", 1);
	}
	if (nbr >= base)
		put_nbr(nbr / base, base, lenght);
	*lenght += write(1, &hexadec[nbr % base], 1);
}