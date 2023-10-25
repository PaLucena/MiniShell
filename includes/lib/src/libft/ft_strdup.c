/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:51:57 by palucena          #+#    #+#             */
/*   Updated: 2023/07/13 16:40:53 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * @brief Allocates sufficient memory for a copy of the string s1,
 * 		  does the copy, and returns a pointer to it.
 * 
 * @param s -> string to copy
 * @return char* -> pointer to the copy of s
 */
char	*ft_strdup(const char *s)
{
	char		*s2;
	size_t		i;

	i = 0;
	s2 = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!s2)
		return (0);
	while (i <= (size_t)(ft_strlen(s)))
	{
		s2[i] = s[i];
		i++;
	}
	return (s2);
}
