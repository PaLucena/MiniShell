/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frankestein.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:39:35 by palucena          #+#    #+#             */
/*   Updated: 2023/12/11 17:54:36 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void	ft_free_all(char *s1, char *s2, char *s3, char *s4)
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

static bool	check_status(char *str, int start, int end)
{
	char	*aux;

	aux = (ft_substr(str, start, end - 1));
	if (ft_strncmp(aux, "$?", 2))
	{
		free(aux);
		return (false);
	}
	free(aux);
	return (true);
}

char	*ft_frankestein(char *base, char *limb, int start, int end)
{
	char	*monster;
	char	*pre;
	char	*post;
	char	*aux;
	int		i;

	post = NULL;   
	pre = ft_substr(base, 0, start);
	i = 0;
	if (check_status(base, start, end))
		end = start + 2;
	while (base[end + i])
		i++;
	if (i >= 1)
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
