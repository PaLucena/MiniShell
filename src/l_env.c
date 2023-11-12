/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:03:29 by palucena          #+#    #+#             */
/*   Updated: 2023/11/12 22:42:04 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*check_keys(char *str, t_env *env, int status)
{
	t_env	*curr;
	char	*aux;

	aux = NULL;
	curr = env;
	if (ft_strncmp(str, "?", 1) == 0)
		aux = ft_itoa(status);
	while (curr)
	{
		if (ft_strcmp(str, curr->key) == 0)
			aux = ft_strdup(curr->value);
		curr = curr->next;
	}
	if (aux)
		return (aux);
	return (NULL);
}

char	*l_get_env(char *str, t_info *info)
{
	char	*new_str;
	char	*aux;
	char	*key;
	int		i;
	int		j;

	i = -1;
	new_str = ft_strdup(str);
	free(str);
	while (new_str[++i])
	{
		if (new_str[i] == '$')
		{
			j = 1;
			while (new_str[i + j + 1] && new_str[i + j + 1] != '$')
				j++;
			aux = ft_substr(new_str, i + 1, j);
			key = check_keys(aux, info->c->list_env, info->status);
			if (key)
				new_str = ft_frankestein(new_str, key, i, i + j + 1);
			else
			{
				new_str = ft_substr(new_str, 0, i);
				break ;
			}
			free(aux);
		}
	}
	return (new_str);
}
