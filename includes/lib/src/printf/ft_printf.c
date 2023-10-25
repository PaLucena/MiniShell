/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:11:52 by palucena          #+#    #+#             */
/*   Updated: 2023/07/13 16:41:54 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_dtype(char const *content, int i, va_list *params)
{
	int	c;

	c = 0;
	if (content[i] == 'c')
		c += ft_printchar(va_arg(*params, int));
	if (content[i] == 's')
		c += ft_printstr(va_arg(*params, char *));
	if (content[i] == 'p')
		c += ft_printptr(va_arg(*params, unsigned long long));
	if (content[i] == 'd')
		c += ft_printdec(va_arg(*params, int));
	if (content[i] == 'i')
		c += ft_printdec(va_arg(*params, int));
	if (content[i] == 'u')
		c += ft_printunsigned(va_arg(*params, unsigned int));
	if (content[i] == 'x')
		c += ft_printhexa(va_arg(*params, unsigned int), 'x');
	if (content[i] == 'X')
		c += ft_printhexa(va_arg(*params, unsigned int), 'X');
	if (content[i] == '%')
		c += ft_printchar('%');
	return (c);
}

/**
 * @brief Outputs the string content to the standard output.
 * 
 * @param content -> string to output
 * @param ... -> variable arguments
 * @return int -> number of characters printed
 */
int	ft_printf(char const *content, ...)
{
	va_list	params;
	int		i;
	int		c;

	i = 0;
	c = 0;
	va_start(params, content);
	while (content[i])
	{
		if (content[i] != '%')
			c += ft_printchar(content[i]);
		else
		{
			i++;
			c += ft_dtype(content, i, &params);
		}
		i++;
	}
	va_end(params);
	return (c);
}
