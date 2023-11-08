/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:50:59 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/13 16:42:20 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_strchr_mod(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin_mod(char const *s1, char const *s2)
{
	char	*str3;
	int		i;
	int		j;
	size_t	len;

	i = 0;
	j = 0;
	len = (ft_strlen((char *)s1) + ft_strlen((char *)s2));
	str3 = malloc(sizeof(char) * (len + 1));
	if (!str3)
		return (NULL);
	while (s1[i])
	{
		str3[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str3[i] = s2[j];
		i++;
		j++;
	}
	str3[i] = '\0';
	return (str3);
}

int	ft_line_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}
