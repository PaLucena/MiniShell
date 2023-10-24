/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:58:13 by rdelicad          #+#    #+#             */
/*   Updated: 2023/10/24 19:33:00 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/env.h"

void	ft_env(t_cmd *c)
{
	while (c->list_env != NULL)
	{
		ft_printf("%s=%s\n", c->list_env->key, c->list_env->value);
		c->list_env = c->list_env->next;
	}
}

void	ft_export(t_cmd *c)
{
	if (c->environment == NULL)
	{
		cases_for_equal_sign(c);
	}
	else
	{
		c->equal_sign = ft_strchr(c->environment, '=');
		if (c->equal_sign != NULL)
		{
			c->key = ft_strldup(c->environment, c->equal_sign - c->environment);
			c->value = ft_strdup(c->equal_sign + 1);
			ft_add_new_env(c);
		}
		free(c->value);
		free(c->key);
	}
}

void	cases_for_equal_sign(t_cmd *c)
{
	while (c->list_env != NULL)
	{
		ft_printf("%s=%s\n", c->list_env->key, c->list_env->value);
		c->list_env = c->list_env->next;
	}
}
