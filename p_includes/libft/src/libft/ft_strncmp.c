/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:30:17 by palucena          #+#    #+#             */
/*   Updated: 2023/07/13 16:41:12 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * @brief Compares the two strings s1 and s2. It returns an integer less than,
 * 		  equal to, or greater than zero if s1 is found, respectively, to be
 * 		  less than, to match, or be greater than s2.
 * 
 * @param s1 -> First string to compare
 * @param s2 -> Second string to compare
 * @param n -> Number of characters to compare
 * @return int -> 0 if the strings are identical, the difference otherwise
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
