/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_builtins.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:25:14 by rdelicad          #+#    #+#             */
/*   Updated: 2023/11/22 16:36:56 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	check_builtin(char	*cmd)
{
	if (cmd == NULL)
		return (false);
	if (ft_strcmp(cmd, "echo") == 0)
		return (true);
	else if (ft_strcmp(cmd, "cd") == 0)
		return (true);
	else if (ft_strcmp(cmd, "pwd") == 0)
		return (true);
	else if (ft_strcmp(cmd, "export") == 0)
		return (true);
	else if (ft_strcmp(cmd, "unset") == 0)
		return (true);
	else if (ft_strcmp(cmd, "env") == 0)
		return (true);
	else if (ft_strcmp(cmd, "exit") == 0)
		return (true);
	else
		return (false);
}

void	ft_builtins2(t_info *i)
{
	if (ft_strcmp(i->par->cmd, "cd") == 0)
	{
		if (i->par->args != NULL)
			i->c->input = i->par->args[0];
		ft_cd(i);
	}
	else if (ft_strcmp(i->par->cmd, "echo") == 0)
		ft_echo(i, i->par->args);
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
			ft_export(i);
	}
	else if (ft_strcmp(i->par->cmd, "unset") == 0)
		ft_unset(i);
	else if (ft_strcmp(i->par->cmd, "pwd") == 0)
		ft_pwd(i->c);
	else
		ft_builtins2(i);
}
