/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:58:13 by rdelicad          #+#    #+#             */
/*   Updated: 2023/10/27 17:48:48 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/env.h"

void	ft_export(t_cmd *c)
{
	if (c->argv_env == NULL)
		normal_export(c);
	else if (ft_strchr(c->argv_env, '='))
		equal_print_env(c);
	else if (!ft_strchr(c->argv_env, '='))
		no_equal_sign(c);
}

void	no_equal_sign(t_cmd *c)
{
	c->key = ft_strdup(c->argv_env);
	c->value = ft_strdup("");
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
	else
	{
		c->key = ft_strdup(c->argv_env);
		c->value = ft_strdup("");
		ft_add_new_env(c);
	}
}

void	normal_export(t_cmd *c)
{
	while (c->list_env != NULL)
	{
		ft_putenv(c, c->list_env->key, c->list_env->value, 1);
		c->list_env = c->list_env->next;
	}
}

void	ft_putenv(t_cmd *c, char *key, char *value, int fd)
{
	char	str[2] = "\"\"";

	if (*value == '\0')
	{
		if (fd == 1)
			write(1, "declare -x ", 11);
		else
			write(1, "declare -xr ", 12);
		ft_putstr_fd(key, fd);
		if (c->argv_env != NULL && ft_strchr(c->argv_env, '='))
		{
			write(1, "=", 1);
			write(1, str, 2);
		}
		write(1, "\n", 1);
	}
	else
	{
		if (fd == 1)
			write(1, "declare -x ", 11);
		else
			write(1, "declare -xr ", 12);
		ft_putstr_fd(key, fd);
		write(1, "=", 1);
		ft_putstr_fd(value, fd);
		write(1, "\n", 1);
	}
}
