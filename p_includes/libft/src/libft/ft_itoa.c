/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:43:34 by palucena          #+#    #+#             */
/*   Updated: 2023/07/13 16:29:02 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_count(long int n)
{
	int	len;

	len = 1;
	while (n >= 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}

/**
 * @brief Allocates (with malloc(3)) and returns a string representing the
 * integer received as an argument. Negative numbers must be handled.
 * 
 * @param n -> integer to convert
 * @return char* -> string representing the integer received as an argument
 */
char	*ft_itoa(int n)
{
	int			len;
	long int	n2;
	char		*n_char;

	n2 = n;
	if (n2 < 0)
		n2 *= -1;
	len = ft_count(n2);
	if (n < 0)
		len++;
	n_char = malloc(sizeof(char) * (len + 1));
	if (!n_char)
		return (0);
	n_char[len--] = 0;
	while (len >= 0)
	{
		n_char[len--] = (n2 % 10) + '0';
		n2 /= 10;
	}
	if (n < 0)
		n_char[0] = '-';
	return (n_char);
}
