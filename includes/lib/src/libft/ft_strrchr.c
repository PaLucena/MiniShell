/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:27:19 by palucena          #+#    #+#             */
/*   Updated: 2023/07/13 16:41:22 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * @brief Returns a pointer to the last occurrence of the character c in
 * 		  the string s.
 * 
 * @param str -> string to search
 * @param c -> character to find
 * @return char* -> pointer to the last occurrence of the character c in
 * 				   the string s
 */
char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == (char) c)
			return ((char *)&str[i]);
		i--;
	}
	return (0);
}
