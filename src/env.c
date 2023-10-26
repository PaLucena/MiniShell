/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:21:05 by rdelicad          #+#    #+#             */
/*   Updated: 2023/10/26 19:50:25 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/env.h"

void	ft_env(t_cmd *c)
{
	while (c->list_env != NULL)
	{
		ft_putstr_fd(c->list_env->key, 1);
		ft_putstr_fd("=", 1);
		ft_putstr_fd(c->list_env->value, 1);
		ft_putstr_fd("\n", 1);
		c->list_env = c->list_env->next;
	}
}
