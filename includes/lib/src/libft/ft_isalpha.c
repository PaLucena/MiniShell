/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:28:13 by palucena          #+#    #+#             */
/*   Updated: 2023/07/12 17:50:30 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks for an alphabetic character
 * 
 * @param c -> character to check
 * @return int -> 1 if c is alphabetic, 0 otherwise
 */
int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
