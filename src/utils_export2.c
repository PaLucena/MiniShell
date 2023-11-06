/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:25:47 by rdelicad          #+#    #+#             */
/*   Updated: 2023/11/06 13:53:31 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/env.h"

void	argv_export(t_cmd *c, char **args, int i)
{
	int j;

	j = 1;
	while (j < i)
	{
		c->argv_env = args[j];
		add_var_export(c);
		j++;
	}
}

void	add_var_export(t_cmd *c)
{
	if (check_argv_exp(c))
		{
			check_env_repeated(c);
			if (c->argv_env != NULL)
			{
				if (ft_strchr(c->argv_env, '='))
					equal_sign_env(c);
				else if (!ft_strchr(c->argv_env, '='))
					no_equal_sign_env(c);
			}
		}
}