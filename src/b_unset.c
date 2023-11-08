/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_unset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:58:05 by rdelicad          #+#    #+#             */
/*   Updated: 2023/11/08 13:05:52 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(t_env **list, char *env)
{
	t_env	*tmp;

	tmp = *list;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, env) == 0)
		{
			top_the_list(list, tmp);
			break;
		}
		else if (ft_strcmp(tmp->next->key, env) == 0)
		{
			if (tmp->next->next == NULL)
				finish_the_list(tmp);
			else
				middle_the_list(tmp);
			break;
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
