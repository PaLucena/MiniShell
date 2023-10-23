/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:58:13 by rdelicad          #+#    #+#             */
/*   Updated: 2023/10/23 22:42:36 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	ft_env(t_cmd *c)
{
	while (c->list_env != NULL)
	{
		printf("%s=%s\n", c->list_env->key, c->list_env->value);
		c->list_env = c->list_env->next;
	}
}

void	ft_export(t_cmd *c)
{
	if (c->environment == NULL)
	{
		while (c->list_env != NULL)
		{
			printf("%s=%s\n", c->list_env->key, c->list_env->value);
			c->list_env = c->list_env->next;
		}
	}
	else
	{
		c->equal_sign = strchr(c->environment, '=');
		if (c->equal_sign != NULL)
		{
			c->key = ft_strldup(c->environment, c->equal_sign - c->environment);
			c->value = strdup(c->equal_sign + 1);
			ft_add_new_env(c);
		}
		free(c->value);
		free(c->key);
	}
}
