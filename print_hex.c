#include "ft_printf.h"

int	print_hex(unsigned int number, char *hexset, int count)
{
	int	temp;

	temp = 0;
	if (number > 15)
	{
		temp = print_hex(number / 16, hexset, count);
		if (temp < 0)
			return (-1);
		count += temp;
	}
	if (print_char(hexset[number % 16]) > 0)
		count++;
	else
		return (-1);
	return (count);
}
