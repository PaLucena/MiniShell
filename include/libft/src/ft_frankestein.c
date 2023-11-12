/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frankestein.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:39:35 by palucena          #+#    #+#             */
/*   Updated: 2023/11/12 22:41:26 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_free_all(char *s1, char *s2, char *s3, char *s4)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	if (s3)
		free(s3);
	if (s4)
		free(s4);
}

bool	check_status(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (false);
	}
	return (true);
}

char	*ft_frankestein(char *base, char *limb, int start, int end)
{
	char	*monster;
	char	*pre;
	char	*post;
	char	*aux;
	int		i;

	pre = NULL;
	post = NULL;
	if (start > 0)
		pre = ft_substr(base, 0, start);
	i = 0;
	if (check_status(limb))
		end = start + 1;
	while (base[end + i])
		i++;
	if (i > 1)
		post = ft_substr(base, end, i);
	if (pre)
		aux = ft_strjoin(pre, limb);
	else
		aux = ft_strdup(limb);
	if (post)
		monster = ft_strjoin(aux, post);
	else
		monster = ft_strdup(aux);
	ft_free_all(pre, aux, post, limb);
	return (monster);
}
