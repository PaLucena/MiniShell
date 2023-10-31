/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:58:05 by rdelicad          #+#    #+#             */
/*   Updated: 2023/10/31 18:22:00 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/env.h"

void	ft_unset(t_cmd *c)
{
	t_env	*tmp;
	t_env	*aux;

	aux = NULL;
	tmp = c->list_env;
	while (tmp)
	{
		if (ft_strcmp(tmp->next->key, c->argv_unset))
		{
			tmp->next->next = aux;
			ft_free_node(tmp->next);
		}
		tmp = tmp->next;
	}
}