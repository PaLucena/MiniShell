/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:53:05 by rdelicad          #+#    #+#             */
/*   Updated: 2023/10/31 12:56:45 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/env.h"

int	check_argv_exp(t_cmd *c)
{
	int	i;

	if (!ft_isalpha(c->argv_env[0]) && c->argv_env[0] != '_')
	{
		ft_error(2, "not a valid identifier");
		return (0);
	}
	i = 1;
	while (c->argv_env[i] != '\0' && c->argv_env[i] != '=')
	{
		if (!ft_isalnum(c->argv_env[i]) && !ft_isalpha(c->argv_env[i])
			&& c->argv_env[i] != '_')
		{
			ft_error(2, "not a valid identifier");
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_value_zero(t_cmd *c, char *key, char *value, int fd)
{
	char	str[2] = "\"\"";

	(void)value;
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

void	ft_value_sign(char *value, int fd)
{
	if (ft_strchr(value, '=') || ft_strchr(value, 32))
		ft_putstr_fd(value, fd);
	else
		ft_putstr_fd(value, fd);
}

void	sorted_list_env(t_env **list_env)
{
	t_env	*curr;
	int		swap;

	// t_env	*last;
	curr = NULL;
	if ((*list_env) == NULL || (*list_env)->next == NULL)
		return ;
	swap = 1;
	while (swap)
	{
		swap = 0;
		curr = (*list_env);
		// last = NULL;
		while (curr->next != NULL)
		{
			if (ft_strcmp(curr->key, curr->next->key) > 0)
			{
				ft_swap_node(curr, curr->next);
				swap = 1;
			}
			// last = curr;
			curr = curr->next;
		}
	}
}

void	ft_swap_node(t_env *a, t_env *b)
{
	char	*aux_key;
	char	*aux_value;
	int		aux_equal;

	aux_key = a->key;
	a->key = b->key;
	b->key = aux_key;
	aux_value = a->value;
	a->value = b->value;
	b->value = aux_value;
	aux_equal = a->equal;
	a->equal = b->equal;
	b->equal = aux_equal;
}
