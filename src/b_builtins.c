/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_builtins.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:25:14 by rdelicad          #+#    #+#             */
/*   Updated: 2023/11/08 17:46:59 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

	
void	ft_builtins(t_info *i)
{
	if (ft_strcmp(i->par->cmd, "env") == 0) 
		ft_env(i->c);
	else if (!ft_strcmp(i->par->cmd, "export")) 
	{
		if (i->par->args != NULL)
			argv_export(i);
		else
			ft_export(i->c);
	}
	else if (ft_strcmp(i->par->cmd, "unset") == 0)
	{
		if (i->par->args != NULL)
			i->c->argv_unset = i->par->args[0];
		ft_unset(&i->c->list_env, i->c->argv_unset);
	}
	else if (ft_strcmp(i->par->cmd, "pwd") == 0)
		ft_pwd(i->c);
	else if (ft_strcmp(i->par->cmd, "cd") == 0)
	{
		if (i->par->args != NULL)
			i->c->input = i->par->args[0];
		ft_cd(i->c);
	}
}
