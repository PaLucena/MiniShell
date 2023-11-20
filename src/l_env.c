/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:03:29 by palucena          #+#    #+#             */
/*   Updated: 2023/11/20 17:12:59 by palucena         ###   ########.fr       */
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

static char	*l_new_str(t_info *info, char *new_str, int i)
{
	char	*aux;
	char	*key;
	int		j;

	j = 2;
	while (new_str[i + j] && new_str[i + j] != '$' && new_str[i + j] != 34
		&& new_str[i + j] != 39 && new_str[i + j] != '/'
		&& new_str[i + j] != ' ')
		j++;
	aux = ft_substr(new_str, i + 1, j);
	key = check_keys(aux, info->c->list_env, info->status);
	free(aux);
	if (key)
		new_str = ft_frankestein(new_str, key, i, i + j + 1);
	else
		return (NULL);
	return (new_str);
}

char	*l_get_env(char *str, t_info *info)
{
	char	*new_str;
	char	*aux;
	int		i;

	i = -1;
	new_str = ft_strdup(str);
	free(str);
	while (new_str[++i])
	{
		if (new_str[i] == '$')
		{
			aux = l_new_str(info, new_str, i);
			if (aux)
			{
				new_str = ft_strdup(aux);
				free(aux);
			}
			else
			{
				new_str = ft_substr(new_str, 0, i);
				break ;
			}
		}
	}
	return (new_str);
}
