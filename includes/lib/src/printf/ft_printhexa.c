/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:32:00 by palucena          #+#    #+#             */
/*   Updated: 2023/07/13 16:41:57 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_printhexa(unsigned long long nb, char ch)
{
	unsigned long long	c;

	c = 0;
	if (nb >= 16)
		c += ft_printhexa(nb / 16, ch);
	if (ch == 'x')
		ft_printchar("0123456789abcdef"[nb % 16]);
	else if (ch == 'X')
		ft_printchar("0123456789ABCDEF"[nb % 16]);
	c++;
	return (c);
}
