/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:04:12 by palucena          #+#    #+#             */
/*   Updated: 2023/07/13 16:40:47 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_wordcount(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

void	ft_free(char **str, int str_ind)
{
	while (str_ind-- > 0)
		free(str[str_ind]);
	free(str);
}

int	ft_len(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

/**
 * @brief Allocates (with malloc(3)) and returns an array of strings obtained
 * 		  by splitting ’s’ using the character ’c’ as a delimiter.
 * 		  The array must be ended by a NULL pointer.
 * 
 * @param s -> The string to be split
 * @param c -> The delimiter character
 * @return char** -> The array of new strings resulting from the split.
 */
char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		str_ind;

	i = 0;
	str_ind = -1;
	str = malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!str)
		return (0);
	while (++str_ind < ft_wordcount(s, c))
	{
		while (s[i] == c)
			i++;
		str[str_ind] = ft_substr(s, i, ft_len(s, c, i));
		if (!(str[str_ind]))
		{
			ft_free(str, str_ind);
			return (0);
		}
		i += ft_len(s, c, i);
	}
	str[str_ind] = 0;
	return (str);
}
