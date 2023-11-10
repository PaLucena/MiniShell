/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_builtins.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:25:14 by rdelicad          #+#    #+#             */
/*   Updated: 2023/11/10 14:28:42 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_builtins2(t_info *i)
{
	if (ft_strcmp(i->par->cmd, "cd") == 0)
	{
		if (i->par->args != NULL)
			i->c->input = i->par->args[0];
		ft_cd(i);
	}
	else if (ft_strcmp(i->par->cmd, "echo") == 0)
		ft_echo(i->par);
	else if (ft_strcmp(i->par->cmd, "exit") == 0)
		ft_exit(i);
}
	
void	ft_builtins(t_info *i)
{
	if (ft_strcmp(i->par->cmd, "env") == 0) 
	{
		if (i->par->args[0] != NULL)
			env_argv(i);
		else
			ft_env(i);
	}
	else if (!ft_strcmp(i->par->cmd, "export")) 
	{
		if (i->par->args[0] != NULL)
			argv_export(i);
		else
			ft_export(i->c);
	}
	else if (ft_strcmp(i->par->cmd, "unset") == 0)
	{
		if (i->par->args[0] != NULL)
			i->c->argv_unset = i->par->args[0];
		ft_unset(&i->c->list_env, i->c->argv_unset);
	}
	else if (ft_strcmp(i->par->cmd, "pwd") == 0)
		ft_pwd(i->c);
	else
		ft_builtins2(i);
}
