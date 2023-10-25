/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:52:27 by palucena          #+#    #+#             */
/*   Updated: 2023/07/13 16:40:56 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * @brief Applies the function f to each character of the string passed
 * 		  as argument, and passing its index as first argument.
 * 		  Each character is passed by address to f to be modified if necessary.
 * 
 * @param s -> string to iterate through and apply f to each character of
 * @param f -> function to apply to each character of s and its index
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}
