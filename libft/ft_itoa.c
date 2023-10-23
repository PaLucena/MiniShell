/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:42:26 by rdelicad          #+#    #+#             */
/*   Updated: 2023/05/02 17:42:39 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(long int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	nb;
	int			len;
	int			sign;

	nb = n;
	len = ft_count_digits(nb);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	sign = 0;
	if (nb < 0)
	{
		str[0] = '-';
		sign = 1;
		nb = -nb;
	}
	while (len-- > sign)
	{
		str[len] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}
