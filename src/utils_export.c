/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:53:05 by rdelicad          #+#    #+#             */
/*   Updated: 2023/10/28 17:53:37 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/env.h"

void	ft_value_zero(t_cmd *c, char *key, char *value, int fd)
{
	(void)value;
	char str[2] = "\"\"";
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
	{
		//write(1, "\"", 1);
		ft_putstr_fd(value, fd);
		//write(1, "\"", 1);
	}
	else
		ft_putstr_fd(value, fd);
}

void	sorted_list_env(t_env **env_list)
{
	t_env				*curr;
	t_env				*next;
	long unsigned int	i;
	long unsigned int	j;
	int					swapped;
	long unsigned int	list_size;

	list_size = 0;
	curr = *env_list;
	while (curr != NULL)
	{
		list_size++;
		curr = curr->next;
	}
	i = 0;
	while (i < list_size - 1)
	{
		swapped = 0;
		curr = *env_list;
		next = (*env_list)->next;
		j = 0;
		while (j < list_size - i - 1)
		{
			if (ft_strcmp(curr->key, next->key) > 0)
			{
				ft_lst_swap(curr, next);
				swapped = 1;
			}
			curr = curr->next;
			next = next->next;
			j++;
		}
		if (swapped == 0)
			break ;
		i++;
	}
}

void	ft_lst_swap(t_env *node_a, t_env *node_b)
{
	t_env	*aux;

	aux = node_a->next;
	node_a->next = node_b->next;
	node_b->next = aux;
}
