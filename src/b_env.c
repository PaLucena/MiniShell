/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:21:05 by rdelicad          #+#    #+#             */
/*   Updated: 2023/11/09 20:10:43 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_info *i)
{
	t_env	*curr;

	env_finish_position(&i->c->list_env);
	curr = i->c->list_env;
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
	i->status = 0;
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

void	env_argv(t_info *i)
{
	write (2, "env: ", 5);
	write (2, i->par->args[0], ft_strlen(i->par->args[0]));
	write (2, ": No such file or directory", 27);
	write (2, "\n", 1);
	i->status = 127;
}

