/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 21:20:27 by palucena          #+#    #+#             */
/*   Updated: 2023/07/13 16:42:06 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_printunsigned(unsigned int nb)
{
	int	c;

	c = 0;
	if (nb >= 10)
		c += ft_printunsigned(nb / 10);
	ft_putchar(nb % 10 + '0');
	c++;
	return (c);
}
