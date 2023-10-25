/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:36:43 by palucena          #+#    #+#             */
/*   Updated: 2023/07/12 17:53:16 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks for an ASCII character, which is any character between 
 * 		  0 and 177 inclusive.
 * 
 * @param c -> character to check
 * @return int -> 1 if c is an ASCII character, 0 otherwise
 */
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
