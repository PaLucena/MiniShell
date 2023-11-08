/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:52:00 by palucena          #+#    #+#             */
/*   Updated: 2023/07/13 16:40:59 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * @brief Allocates (with malloc(3)) and returns a new string, which is the
 * 		  result of the concatenation of ’s1’ and ’s2’.
 * 
 * @param s1 -> The prefix string
 * @param s2 -> The suffix string
 * @return char* -> The new string. NULL if the allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*s_total;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	s_total = (char *)malloc((i + j + 1) * sizeof(char));
	if (!s_total)
		return (0);
	i = -1;
	while (s1[++i])
		s_total[i] = s1[i];
	j = -1;
	while (s2[++j])
	{
		s_total[i] = s2[j];
		i++;
	}
	s_total[i] = 0;
	return (s_total);
}
