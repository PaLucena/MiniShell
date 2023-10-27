/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:58:13 by rdelicad          #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2023/10/26 21:28:26 by rdelicad         ###   ########.fr       */
=======
/*   Updated: 2023/10/27 20:49:36 by rdelicad         ###   ########.fr       */
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#include "../include/env.h"

void	ft_export(t_cmd *c)
{
	if (c->argv_env == NULL)
		ft_putenv(c, 1);
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
	copy_env_list(c);
	print_sorted_list(c);
	//sort_env_list(c);
	while (c->list_env != NULL)
	{
		ft_putenv(c, c->list_env->key, c->list_env->value, 1);
		c->list_env = c->list_env->next;
	}
}

void	ft_putenv(t_cmd *c, char *key, char *value, int fd)
{
	if (*value == '\0')
	{
		ft_value_zero(c, key, value, fd);
	}
	else
	{
		if (fd == 1)
			write(1, "declare -x ", 11);
		else
			write(1, "declare -xr ", 12);
		ft_putstr_fd(key, fd);
		write(1, "=", 1);
		if (ft_strchr(value, '='))
		{
			write(1, "\'", 1);
			ft_putstr_fd(value, fd);
			write(1, "\'", 1);
		}
		else
			ft_putstr_fd(value, fd);
		write(1, "\n", 1);
	}
}
