/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:38:48 by palucena          #+#    #+#             */
/*   Updated: 2023/07/13 16:41:09 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * @brief Applies the function f to each character of the string passed
 * 		  as argument by giving its index as first argument to create a
 * 		  “fresh” new string (with malloc(3)) resulting from the successive
 * 		  applications of f.
 * 
 * @param s -> string to iterate through and apply f to each character of
 * @param f -> function to apply to each character of s and its index
 * @return char* -> The “fresh” string created from the successive applications
 * 				    of f.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	if (!s || !f)
		return (0);
	i = ft_strlen(s);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
