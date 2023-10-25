/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:37:13 by palucena          #+#    #+#             */
/*   Updated: 2023/07/13 13:39:31 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Locates the first occurrence of ’c’ (converted to a char) in 
 * 		  the string pointed to by ’s’.
 * 
 * @param str -> string to search
 * @param c -> character to search
 * @return char* -> pointer to the located character
 */
char	*ft_strchr(const char *str, int c)
{
	if (!*str && (char) c == '\0')
		return ((char *) str);
	while (*str != '\0')
	{
		if (*str == (char) c)
			return ((char *) str);
		str++;
		if (*str == (char) c)
			return ((char *) str);
	}
	return (0);
}
