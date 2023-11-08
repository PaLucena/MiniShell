/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 20:50:45 by palucena          #+#    #+#             */
/*   Updated: 2023/07/13 16:42:00 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_printptr(unsigned long long ptr)
{
	int	c;

	c = 0;
	c += ft_printstr("0x");
	c += ft_printhexa(ptr, 'x');
	return (c);
}
