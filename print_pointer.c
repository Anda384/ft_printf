#include "ft_printf.h"

int	hex(unsigned long nbr, char *hexset, int count)
{
	int	temp;

	temp = 0;
	if (nbr > 15)
	{
		temp = hex(nbr / 16, hexset, count);
		if (temp < 0)
			return (-1);
		count += temp;
	}
	if (print_char(hexset[nbr % 16]) > 0)
		count++;
	else
		return (-1);
	return (count);
}

int	print_pointer(unsigned long n, char *base, int count)
{
	int	temp;

	temp = 0;
	if (print_str("0x") < 0)
		return (-1);
	temp = hex(n, base, count);
	if (temp < 0)
		return (temp);
	return (temp + 2);
}