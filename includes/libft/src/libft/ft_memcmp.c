/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:24:28 by palucena          #+#    #+#             */
/*   Updated: 2023/07/13 16:40:18 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * @brief Compares byte string s1 against byte string s2.  Both strings are
 * 		  assumed to be n bytes long.
 * 
 * @param s1 -> pointer to the first memory area
 * @param s2 -> pointer to the second memory area
 * @param n -> number of bytes to be compared
 * @return int -> zero if the two strings are identical, otherwise returns the
 * 				  difference between the first two differing bytes
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*pt_s1;
	unsigned char	*pt_s2;
	size_t			i;

	pt_s1 = (unsigned char *) s1;
	pt_s2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (pt_s1[i] != pt_s2[i])
			return (pt_s1[i] - pt_s2[i]);
		i++;
	}
	return (0);
}
