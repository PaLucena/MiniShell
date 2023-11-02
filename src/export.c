/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:58:35 by rdelicad          #+#    #+#             */
/*   Updated: 2023/11/02 10:42:43 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/env.h"

void	ft_export(t_cmd *c)
{
	if (c->argv_env == NULL)
		normal_export(c);
	else
	{
		if (check_argv_exp(c))
		{
			check_env_repeated(c);
			if (c->argv_env != NULL)
			{
				if (ft_strchr(c->argv_env, '='))
					equal_sign_env(c);
				else if (!ft_strchr(c->argv_env, '='))
					no_equal_sign_env(c);
			}
		}
	}
}

void	no_equal_sign_env(t_cmd *c)
{
	c->key = ft_strdup(c->argv_env);
	c->value = ft_strdup("");
	ft_add_new_env(c);
	free(c->key);
	free(c->value);
}

void	equal_sign_env(t_cmd *c)
{
	c->equal_sign = ft_strchr(c->argv_env, '=');
	if (c->equal_sign != NULL)
	{
		no_value(c);
		yes_value(c);
		ft_add_new_env(c);
		free(c->key);
		free(c->value);
		c->argv_env = NULL;
	}
	else
	{
		c->key = ft_strdup(c->argv_env);
		c->value = ft_strdup("");
		ft_add_new_env(c);
		free(c->key);
		free(c->value);
	}
}

void	normal_export(t_cmd *c)
{
	t_env	*curr;

	/* ft_printf("---------- Comando ENV ------------\n");
	ft_env(c);
	ft_printf("---------- Comando EXPORT ------------\n");
	ft_printf("\n"); */
	sorted_list_env(&c->list_env);
	curr = c->list_env;

	while (curr != NULL)
	{
		ft_putenv(curr->key, curr->value, curr->equal, 1);
		curr = curr->next;
	}
	ft_printf("\n");
}

void	ft_putenv(char *key, char *value, int equal, int fd)
{
	if (*value == '\0')
	{
		ft_value_zero(key, equal, fd);
	}
	else
	{
		if (fd == 1)
			write(1, "declare -x ", 11);
		else
			write(1, "declare -xr ", 12);
		ft_putstr_fd(key, fd);
		write(1, "=", 1);
		if (!ft_strchr(value, 34))
		{
			write(1, "\"", 1);
			ft_value_sign(value, fd);
			write(1, "\"", 1);
		}
		else
			ft_value_sign(value, fd);
		write(1, "\n", 1);
	}
}
