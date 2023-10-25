/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:44:16 by palucena          #+#    #+#             */
/*   Updated: 2023/07/13 16:40:28 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * @brief Fills the first n bytes of the memory area pointed to by s with the
 * 		  constant byte c.
 * 
 * @param str -> pointer to the memory area
 * @param c -> value to be set
 * @param len -> number of bytes to be set to the value
 * @return void* -> pointer to the memory area str
 */
void	*ft_memset(void *str, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)str;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
