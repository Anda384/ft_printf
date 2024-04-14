#include "ft_printf.h"

int	print_char(int c)
{
	if (write(1, &c, 1) <  0)
		return (-1);
	else
		return (1);
}

int	print_str(const char *str)
{
	int	count;

	count = 0;
	if(str == NULL)
		return (print_str("(null)"));
	while (*str)
	{
		if (write(1, str, 1) < 0)
			return ((-1));
		else
		{
			count++;
			str++;
		}
	}
	return (count);
}

static int	check_type(const char *str, va_list args)
{
	char *hex;

	hex = "0123456789abcdef";
	if (*str == 'c')
		return (print_char(va_arg(args, int)));
	else if (*str == 's')
		return (print_str(va_arg(args, char *)));
	else if (*str == 'd')
		return (print_decimal(va_arg(args, int)));
	else if (*str == 'i')
		return (print_decimal(va_arg(args, int)));
	else if (*str == 'X')
		return (print_hex(va_arg(args, unsigned int), "0123456789ABCDEF", 0));
	else if (*str == 'x')
		return (print_hex(va_arg(args, unsigned int), "0123456789abcdef", 0));
	else if (*str == 'u')
		return (print_decimal(va_arg(args, unsigned int)));
	else if (*str == 'p')
	{
		return (print_pointer((unsigned long)(va_arg(args, void *)), hex, 0));
	}
	else
		return (print_char('%'));
}

int ft_printf(const char *str, ...)
{
	va_list	args;
	int		temp;
	int		count;

	count = 0,
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			temp = check_type(++str, args);
			if (temp < 0)
				return (-1);
			count += temp;
		}
		else
		{
			temp = write(1, str, 1);
			if (temp < 0)
				return (-1);
			count += temp;
		}
		str++;
	}
	return (count);
}