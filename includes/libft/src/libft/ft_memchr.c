/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:31:18 by palucena          #+#    #+#             */
/*   Updated: 2023/07/13 16:40:14 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * @brief Scans the initial n bytes of the memory area pointed to by s for the
 * first instance of c. Both c and the bytes of the memory area pointed to by s
 * are interpreted as unsigned char.
 * 
 * @param s -> pointer to the memory area
 * @param c -> character to be located
 * @param n -> number of bytes to be analyzed
 * @return void* -> pointer to the matching byte or NULL if the character does
 * 					not occur in the given memory area
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*pt_s;

	pt_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (pt_s[i] == (unsigned char) c)
			return (&pt_s[i]);
		i++;
	}
	return (0);
}
