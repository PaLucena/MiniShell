/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:16:32 by rdelicad          #+#    #+#             */
/*   Updated: 2023/10/24 20:02:01 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char	*dst;
	unsigned char	*src;

	src = (unsigned char *)s2;
	dst = (unsigned char *)s1;
	if (dst == src)
		return (dst);
	if (dst < src)
		ft_memcpy(dst, src, n);
	else
	{
		while (n > 0)
		{
			n--;
			dst[n] = src[n];
		}
	}
	return (dst);
}
