/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:58:13 by rdelicad          #+#    #+#             */
/*   Updated: 2023/10/23 19:41:44 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	ft_export(t_cmd *c)
{
	char	*equal;

	if (c->environment == NULL)
	{
		while (c->list_env != NULL)
		{
			printf("%s%s\n", c->list_env->key, c->list_env->value);
			c->list_env = c->list_env->next;
		}
	}
	else
	{
		equal = (strchr(c->environment, '=') + 1);
		if (equal != NULL)
		{
			*equal = '\0';
			c->key = strdup(c->environment);
			c->value = strdup(equal + 1);
			add_env(c);
		}
	}
}
