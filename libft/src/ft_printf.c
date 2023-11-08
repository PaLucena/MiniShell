/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:54:47 by rdelicad          #+#    #+#             */
/*   Updated: 2023/10/24 20:02:09 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	print_digit(long n, int base, int letters)
{
	int		cont;
	char	*symbols;

	if (letters < 0)
		symbols = "0123456789abcdef";
	else
		symbols = "0123456789ABCDEF";
	if (n == 0)
		return (print_char('0'));
	if (n < 0)
	{
		write (1, "-", 1);
		return (print_digit(-n, base, 1) + 1);
	}
	else if (n < base)
		return (print_char(symbols[n]));
	else
	{
		cont = print_digit(n / base, base, letters);
		return (cont + print_digit(n % base, base, letters));
	}
}

int	print_pointer(unsigned long ptr)
{
	int	cont;

	cont = 0;
	print_str("0x");
	cont += 2;
	cont += print_hexa(ptr);
	return (cont);
}

int	print_format(char specifier, va_list ap)
{
	int					cont;

	cont = 0;
	if (specifier == 'c')
		cont += print_char(va_arg(ap, int));
	else if (specifier == 's')
		cont += print_str(va_arg(ap, char *));
	else if (specifier == 'd')
		cont += print_digit((long)va_arg(ap, int), 10, 1);
	else if (specifier == 'i')
		cont += print_digit((long)va_arg(ap, int), 10, 1);
	else if (specifier == 'x')
		cont += print_digit((long)va_arg(ap, unsigned int), 16, -1);
	else if (specifier == 'X')
		cont += print_digit((long)va_arg(ap, unsigned int), 16, 1);
	else if (specifier == 'p')
		cont += print_pointer(va_arg(ap, unsigned long));
	else if (specifier == 'u')
		cont += print_digit(va_arg(ap, unsigned int), 10, -1);
	else if (specifier == '%')
		cont += write (1, &specifier, 1);
	return (cont);
}

int	ft_printf(char const *format, ...)
{
	va_list	ap;
	int		cont;

	va_start(ap, format);
	cont = 0;
	while (*format)
	{
		if (*format != '%')
		{
			print_char(*format);
			cont++;
		}
		else
		{
			format++;
			cont += print_format(*format, ap);
		}
		format++;
	}
	va_end(ap);
	return (cont);
}
