/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:21:05 by rdelicad          #+#    #+#             */
/*   Updated: 2023/11/08 13:05:32 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_cmd *c)
{
	t_env	*curr;

	env_finish_position(&c->list_env);
	curr = c->list_env;
	while (curr != NULL)
	{
		if (curr->equal == 1)
		{
			ft_putstr_fd(curr->key, 1);
			ft_putstr_fd("=", 1);
			ft_putstr_fd(curr->value, 1);
			ft_putstr_fd("\n", 1);
		}
		curr = curr->next;
	}
	ft_printf("\n");
}

void	env_finish_position(t_env **env)
{
	t_env	*curr;
	t_env	*prev;

	curr = *env;
	prev = NULL;
	while (curr != NULL)
	{
		if (curr->key[0] == '_' && curr->key[1] == '\0')
		{
			if (prev == NULL)
				*env = curr->next;
			else
				prev->next = curr->next;
			curr->next = NULL;
			ft_lstadd_back_env(env, curr);
		}
		prev = curr;
		curr = curr->next;
	}
}

