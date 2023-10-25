/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 20:47:09 by palucena          #+#    #+#             */
/*   Updated: 2023/07/13 16:41:48 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 0 && nb <= 9)
		ft_putchar(nb + '0');
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}		
}

static int	ft_dcount(long int nb)
{
	int	i;

	i = 0;
	while (nb >= 10)
	{
		nb /= 10;
		i++;
	}
	return (i + 1);
}

int	ft_printdec(int nb)
{
	long int	c;

	c = 0;
	ft_putnbr(nb);
	if (nb >= 0)
		return (ft_dcount(nb));
	c = (long int)nb * (-1);
	return (ft_dcount(c) + 1);
}
