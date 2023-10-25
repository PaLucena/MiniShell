/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:20:15 by palucena          #+#    #+#             */
/*   Updated: 2023/07/13 16:41:32 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * @brief Allocates (with malloc(3)) and returns a substring from the string ’s’.
 * 		  The substring begins at index ’start’ and is of maximum size ’len’.
 * 
 * @param s -> The string from which to create the substring.
 * @param start -> The start index of the substring in the string ’s’.
 * @param len -> The maximum length of the substring.
 * @return char* -> The substring. NULL if the allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if ((size_t)ft_strlen(s) < start)
		return (ft_strdup(""));
	if ((size_t)ft_strlen(s) < start + len)
		len = ft_strlen(s) - start;
	sub = malloc((len + 1) * sizeof(char));
	if (!sub || !s)
		return (0);
	i = 0;
	while (s[start])
	{
		if (i < len)
		{
			sub[i] = s[start];
			i++;
		}
		start++;
	}
	sub[i] = 0;
	return (sub);
}
