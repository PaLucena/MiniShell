/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:39:07 by palucena          #+#    #+#             */
/*   Updated: 2023/07/13 16:41:01 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * @brief size-bounded string concatenation (strlcat) that takes the full size
 * 		  of the destination buffer and guarantee NUL-termination if there is
 * 		  room.
 * 
 * @param dest -> destination string
 * @param src -> source string
 * @param size -> size of the destination buffer
 * @return size_t -> the total length of the string they tried to create
 */
size_t	ft_strlcat(char *dest, char *src, unsigned int size)
{
	size_t	i;
	size_t	j;
	size_t	res;

	i = 0;
	j = 0;
	res = 0;
	while (dest[i] != '\0')
		i++;
	while (src[res] != '\0')
		res++;
	if (size <= i)
		res += size;
	else
		res += i;
	while (src[j] != '\0' && (i + 1) < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (res);
}
