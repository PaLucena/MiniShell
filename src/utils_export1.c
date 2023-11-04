/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:26:36 by rdelicad          #+#    #+#             */
/*   Updated: 2023/11/03 14:49:09 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/env.h"

int	check_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' || str[i] != '=')
	{
		if (str[i] == 32 && (str[i + 1] == '=' || str[i - 1] == '='))
			return (1);
		i++;
	}
	return (0);
}

void	yes_value(t_cmd *c)
{
	c->key = ft_strldup(c->argv_env, c->equal_sign - c->argv_env);
	c->value = ft_strdup(c->equal_sign + 1);
}

void	no_value(t_cmd *c)
{
	int	i;

	i = 0;
	while (c->argv_env[i] != '=')
		i++;
	if (c->argv_env[i + 1] == '\0')
	{
		c->key = ft_strldup(c->argv_env, c->equal_sign - c->argv_env);
		c->value = ft_strdup("");
	}
}

void	check_env_repeated(t_cmd *c)
{
	t_env	*curr;

	separate_env(c);
	curr = c->list_env;
	while (curr)
	{
		if (ft_strcmp(curr->key, c->key) == 0)
		{
			if ((curr->equal == 1 || curr->equal == 0) && ft_strchr(c->argv_env,
					'='))
			{
				free(curr->value);
				curr->value = ft_strdup(c->value);
				curr->equal = 1;
				free(c->value);
				free(c->key);
				c->argv_env = NULL;
				break ;
			}
			free(c->key);
			free(c->value);
			c->argv_env = NULL;
		}
		curr = curr->next;
	}
}

void	separate_env(t_cmd *c)
{
	c->equal_sign = ft_strchr(c->argv_env, '=');
	if (c->equal_sign != NULL)
	{
		c->key = ft_strldup(c->argv_env, c->equal_sign - c->argv_env);
		c->value = ft_strdup(c->equal_sign + 1);
	}
	else
	{
		c->key = ft_strdup(c->argv_env);
		c->value = ft_strdup("");
	}
}
