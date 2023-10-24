/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:24:44 by rdelicad          #+#    #+#             */
/*   Updated: 2023/10/24 20:01:55 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s2;
	str2 = (unsigned char *)s1;
	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (i < n - 1 && *str1 == *str2)
	{
		str1++;
		str2++;
		i++;
	}
	return (*str2 - *str1);
}
