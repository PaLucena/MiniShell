/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:53:05 by rdelicad          #+#    #+#             */
/*   Updated: 2023/11/23 22:41:23 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	ft_value_zero(char *key, char *value, int equal, int fd)
{
	char	str[2];

	ft_strlcpy(str, "\"\"", 3);
	if (fd == 1)
		write(1, "declare -x ", 11);
	ft_putstr_fd(key, fd);
	if (equal == 1 && (ft_strcmp(key, "OLDPWD") == 0
			&& ft_strcmp(value, "") != 0))
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

	curr = NULL;
	if ((*list_env) == NULL || (*list_env)->next == NULL)
		return ;
	swap = 1;
	while (swap)
	{
		swap = 0;
		curr = (*list_env);
		while (curr->next != NULL)
		{
			if (ft_strcmp(curr->key, curr->next->key) > 0)
			{
				ft_swap_node(curr, curr->next);
				swap = 1;
			}
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
