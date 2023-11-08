/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:25:14 by rdelicad          #+#    #+#             */
/*   Updated: 2023/11/07 19:54:21 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/env.h"

	
void	ft_builtins(t_cmd *c, char **args, int i)
{
	if (strcmp(args[0], "env") == 0) 
		ft_env(c);
	else if (!strcmp(args[0], "export")) 
	{
		if (i > 1)
			argv_export(c, args, i);
		else
			ft_export(c);
	}
	else if (strcmp(args[0], "unset") == 0)
	{
		if (i > 1)
			c->argv_unset = args[1];
		ft_unset(&c->list_env, c->argv_unset);
	}
	else if (strcmp(args[0], "pwd") == 0)
		ft_pwd(c);
	else if (strcmp(args[0], "cd") == 0)
	{
		if (i > 1)
			c->input = args[1];
		ft_cd(c);
	}
	else
		ft_printf("Comando inválido.\n");
}
