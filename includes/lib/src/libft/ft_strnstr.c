/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:38:36 by palucena          #+#    #+#             */
/*   Updated: 2023/09/11 16:57:02 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * @brief Locates the first occurrence of the null-terminated string little in
 * 		  the string big, where not more than len characters are searched.
 * 		  Characters that appear after a `\0' character are not searched.
 * 
 * @param str -> string to search
 * @param to_find -> string to find
 * @param n -> number of characters to search
 * @return char* -> pointer to the first occurrence of the string to_find in str
 */
char	*ft_strnstr(char *str, char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	if (to_find[0] == '\0')
		return ((char *)str);
	i = 0;
	while (str[i] != '\0' && (size_t)i < n)
	{
		j = 0;
		while (to_find[j] != '\0' && (size_t)i + j < n)
		{
			if (str[i + j] == to_find[j])
				j++;
			else
				break ;
		}
		if (to_find[j] == '\0')
			return ((char *)str + i);
		i++;
	}
	return (0);
}
