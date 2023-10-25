/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:44:58 by palucena          #+#    #+#             */
/*   Updated: 2023/07/13 16:41:05 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * @brief Copy string src to buffer dest of size destsize.
 * 
 * @param dest -> destination string
 * @param src -> source string
 * @param size -> size of the destination buffer
 * @return size_t -> the total length of the string they tried to create
 */
size_t	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while (src[res])
		res++;
	if (size > 0)
	{
		while (src[i] && i < (size -1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (res);
}
