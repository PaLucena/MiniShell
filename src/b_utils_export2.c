/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils_export2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:25:47 by rdelicad          #+#    #+#             */
/*   Updated: 2023/11/09 14:00:59 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	argv_export(t_info *i)
{
	int j;

	j = 0;
	while (i->par->args[j] != NULL)
	{
		i->c->argv_env = i->par->args[j];
		add_var_export(i->c);
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
