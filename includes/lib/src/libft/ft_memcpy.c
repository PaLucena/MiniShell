/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:09:58 by palucena          #+#    #+#             */
/*   Updated: 2023/07/13 16:40:21 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * @brief Copies n bytes from memory area src to memory area dest.
 * 
 * @param dest -> pointer to the destination array where the content 
 * 				  is to be copied
 * @param src -> pointer to the source of data to be copied
 * @param n -> number of bytes to copy
 * @return void* -> pointer to dest
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*pt_dest;
	const char	*pt_src;

	if (!src && !dest)
		return (0);
	i = 0;
	pt_dest = (char *)dest;
	pt_src = (const char *)src;
	while (i < n)
	{
		pt_dest[i] = pt_src[i];
		i++;
	}
	return (dest);
}
