/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_unset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:58:05 by rdelicad          #+#    #+#             */
/*   Updated: 2023/11/11 17:12:27 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(t_info *i)
{
	t_env	*tmp;

	if (i->par->args[0] == NULL)
		return ;
	tmp = i->c->list_env;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, i->par->args[0]) == 0)
		{
			top_the_list(&i->c->list_env, tmp);
			i->status = 0;
			break ;
		}
		else if (ft_strcmp(tmp->next->key, i->par->args[0]) == 0)
		{
			if (tmp->next->next == NULL)
				finish_the_list(tmp);
			else
				middle_the_list(tmp);
			i->status = 0;
			break ;
		}
		tmp = tmp->next;
	}
}

void	top_the_list(t_env **list, t_env *new)
{
	free(new->key);
	free(new->value);
	*list = new->next;
	free(new);
}

void	middle_the_list(t_env *new)
{
	free(new->next->key);
	free(new->next->value);
	free(new->next);
	new->next = new->next->next;
}

void	finish_the_list(t_env *new)
{
	free(new->next->key);
	free(new->next->value);
	free(new->next);
	new->next = NULL;
}
