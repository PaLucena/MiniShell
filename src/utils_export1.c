/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:26:36 by rdelicad          #+#    #+#             */
/*   Updated: 2023/10/31 19:42:25 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/env.h"

int	check_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' || str[i] != '=')
	{
		if (str[i] == 32 && (str[i + 1] == '=' || str[i - 1] == '='))
			return (1);
		i++;
	}
	return (0);
}

void	yes_value(t_cmd *c)
{
	c->key = ft_strldup(c->argv_env, c->equal_sign - c->argv_env);
	c->value = ft_strdup(c->equal_sign + 1);
}

void	no_value(t_cmd *c)
{
	int	i;

	i = 0;
	while (c->argv_env[i] != '=')
		i++;
	if (c->equal_sign[i + 1] == '\0')
	{
		c->key = ft_strldup(c->argv_env, c->equal_sign - c->argv_env);
		c->value = ft_strdup("");
	}
}
