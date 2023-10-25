/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:33:47 by palucena          #+#    #+#             */
/*   Updated: 2023/09/21 17:18:54 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks for a digit (0 through 9).
 * 
 * @param c -> character to check
 * @return int -> 1 if c is a digit, 0 otherwise
 */
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
