/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:21:05 by rdelicad          #+#    #+#             */
/*   Updated: 2023/10/31 18:01:33 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/env.h"

void	ft_env(t_cmd *c)
{
	t_env	*curr;

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
