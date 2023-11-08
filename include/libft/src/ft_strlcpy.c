/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:19:41 by rdelicad          #+#    #+#             */
/*   Updated: 2023/10/24 20:03:28 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	len;

	srclen = ft_strlen(src);
	if (size > 0)
	{
		if (srclen >= size)
		{
			len = size - 1;
		}
		else
		{
			len = srclen;
		}
		ft_memcpy(dst, src, len);
		dst[len] = '\0';
	}
	return (srclen);
}
