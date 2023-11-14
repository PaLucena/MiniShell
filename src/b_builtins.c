/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_builtins.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:25:14 by rdelicad          #+#    #+#             */
/*   Updated: 2023/11/14 20:08:26 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		ft_unset(i);
	else if (ft_strcmp(i->par->cmd, "pwd") == 0)
		ft_pwd(i->c);
	else if (ft_strcmp(i->par->cmd, "cd") == 0)
		ft_cd(i);
	else if (ft_strcmp(i->par->cmd, "exit") == 0)
		ft_exit(i);
}
