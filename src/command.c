/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:58:13 by rdelicad          #+#    #+#             */
/*   Updated: 2023/10/25 21:08:11 by rdelicad         ###   ########.fr       */
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
	if (c->argv_env == NULL)
		cmd_print_export(c);
	else if (ft_strchr(c->argv_env, '='))
		equal_print_env(c);
	else if (!ft_strchr(c->argv_env, '='))
		no_equal_sign(c);
}

void	no_equal_sign(t_cmd *c)
{
	c->equal_sign = ft_strchr(c->argv_env, '\0');
	c->key = ft_strldup(c->argv_env, c->equal_sign - c->argv_env);
	c->value = NULL;
	ft_add_new_env(c);
}

void	equal_print_env(t_cmd *c)
{
	c->equal_sign = ft_strchr(c->argv_env, '=');
	if (c->equal_sign != NULL)
	{
		c->key = ft_strldup(c->argv_env, c->equal_sign - c->argv_env);
		c->value = ft_strdup(c->equal_sign + 1);
		ft_add_new_env(c);
	}
}

void	cmd_print_export(t_cmd *c)
{
	while (c->list_env != NULL)
	{
		ft_printf("%s=%s\n", c->list_env->key, c->list_env->value);
		c->list_env = c->list_env->next;
	}
}
