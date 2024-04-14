#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	print_char(int c);
int	print_str(const char *str);
int	print_decimal(long n);
int	print_hex(unsigned int number, char *hexset, int count);
int	hex(unsigned long n, char *hexset, int count);
int	print_pointer(unsigned long n, char *base, int count);
int	ft_printf(const char *str, ...);

#endif