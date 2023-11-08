/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:06:35 by rdelicad          #+#    #+#             */
/*   Updated: 2023/10/24 20:02:56 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_strclen(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static int	ft_count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*ft_strndup(char const *s1, size_t n)
{
	char	*ptr;

	ptr = (char *)malloc(n + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s1, n);
	ptr[n] = '\0';
	return (ptr);
}

static void	ft_freememory(char **strs, int i)
{
	while (--i >= 0)
		free(strs[i]);
	free(strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	strs = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!strs)
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ft_count_words(s, c))
	{
		while (s[j] == c)
			j++;
		strs[i] = ft_strndup(s + j, ft_strclen(s + j, c));
		if (!strs[i])
		{
			ft_freememory(strs, i);
			return (NULL);
		}
		j += ft_strclen(s + j, c);
	}
	strs[i] = NULL;
	return (strs);
}
