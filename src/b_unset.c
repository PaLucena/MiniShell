/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_unset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:58:05 by rdelicad          #+#    #+#             */
/*   Updated: 2023/11/18 15:17:03 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(t_info *i)
{
	if (i->par->args[0] == NULL)
		return ;
	else if (top_the_list(i))
		return ;
	else if (middle_the_list(i))
		return ;
	else if (finish_the_list(i))
		return ;
	/* tmp = i->c->list_env;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, i->par->args[0]) == 0)
		{
			top_the_list(&i->c->list_env, tmp, i);
			break ;
		}
		else if (tmp->next != NULL && ft_strcmp(tmp->next->key,
				i->par->args[0]))
		{
			if (tmp->next->next == NULL)
				finish_the_list(tmp);
			else
				middle_the_list(tmp);
			i->status = 0;
			break ;
		}
		tmp = tmp->next;
	} */
}

int	top_the_list(t_info *i)
{
	t_env	*tmp;

	tmp = i->c->list_env;
	if (ft_strcmp(tmp->key, i->par->args[0]) == 0)
	{
		i->c->list_env = tmp->next;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
		i->status = 0;
		return (1);
	}
	return (0);
}

int	middle_the_list(t_info *i)
{
	t_env	*tmp;
	t_env	*to_free;

	tmp = i->c->list_env;
	while (tmp != NULL && tmp->next != NULL)
	{
		if (ft_strcmp(tmp->next->key, i->par->args[0]) == 0)
		{
			to_free = tmp->next;
			tmp->next = tmp->next->next;
			free(to_free->key);
			free(to_free->value);
			free(to_free);
			i->status = 0;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}


int	finish_the_list(t_info *i)
{
	t_env	*tmp;
	t_env	*prev;

	tmp = i->c->list_env;
	prev = NULL;
	while (tmp->next != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (ft_strcmp(tmp->key, i->par->args[0]) == 0)
	{
		free(tmp->key);
		free(tmp->value);
		free(tmp);
		if (prev != NULL)
			prev->next = NULL;
		else
			i->c->list_env = NULL;
		i->status = 0;
		return (1);
	}
	return (0);
}

