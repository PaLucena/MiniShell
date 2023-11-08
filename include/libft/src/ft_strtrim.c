/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:34:02 by rdelicad          #+#    #+#             */
/*   Updated: 2023/10/24 20:03:51 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*trimmed_str;
	size_t	start;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	len = ft_strlen(&s1[start]);
	if (len > 0)
	{
		while (s1[start + len - 1] && ft_strchr(set, s1[start + len - 1]))
			len--;
	}
	trimmed_str = ft_substr(s1, start, len);
	return (trimmed_str);
}
