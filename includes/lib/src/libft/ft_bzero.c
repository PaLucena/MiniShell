/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:58:16 by palucena          #+#    #+#             */
/*   Updated: 2023/07/13 16:28:25 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * @brief Writes n zeroed bytes to the string str. If n is zero,
 * 		  bzero() does nothing.
 * 
 * @param str -> string to write
 * @param n -> number of bytes to write
 */
void	ft_bzero(void *str, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)str;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
