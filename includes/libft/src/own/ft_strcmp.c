/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:20:11 by palucena          #+#    #+#             */
/*   Updated: 2023/10/20 14:51:01 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * @brief Compares the string s1 against the string s2.
 * 
 * @param s1 -> First string to compare
 * @param s2 -> Second string to compare
 * @return int -> 0 if the strings are identical, 
 * 				  otherwise returns the difference
 */
bool	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*(unsigned char *)s1 - *(unsigned char *)s2 == 0)
		return (true);
	return (false);
}
