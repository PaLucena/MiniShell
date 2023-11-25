/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_builtins.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:25:14 by rdelicad          #+#    #+#             */
/*   Updated: 2023/11/25 19:19:31 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	check_builtin(char	*cmd)
{
	if (!cmd)
		return (false);
	else if (b_check_mayus(cmd, "echo"))
		return (true);
	else if (b_check_mayus(cmd, "cd"))
		return (true);
	else if (b_check_mayus(cmd, "pwd"))
		return (true);
	else if (b_check_mayus(cmd, "export"))
		return (true);
	else if (b_check_mayus(cmd, "unset"))
		return (true);
	else if (b_check_mayus(cmd, "env"))
		return (true);
	else if (b_check_mayus(cmd, "exit"))
		return (true);
	return (false);
}

bool	b_check_mayus(char *str, char *cmd)
{
	char	*check;
	int		i;

	check = malloc(sizeof(char) * (ft_strlen(str) + 1));
	i = -1;
	while (str[++i])
		check[i] = ft_tolower(str[i]);
	check[i] = '\0';
	if (!ft_strcmp(check, cmd))
	{
		free(check);
		return (true);
	}
	free(check);
	return (false);
}

static void	ft_builtins3(t_info *i)
{
	if (b_check_mayus(i->par->cmd, "cd"))
	{
		if (i->par->args != NULL)
			i->c->input = i->par->args[0];
		if (!ft_strcmp(i->par->cmd, "cd"))
			ft_cd(i);
	}
	else if (b_check_mayus(i->par->cmd, "exit"))
	{
		if (ft_strcmp(i->par->cmd, "exit"))
		{
			i->status = 127;
			ft_error_msg(i, 0);
			if (i->n_cmds > 1)
				exit(i->status);
		}
		ft_exit(i);
	}
}

static void	ft_builtins2(t_info *i)
{
	if (b_check_mayus(i->par->cmd, "export"))
	{
		if (!ft_strcmp(i->par->cmd, "export"))
		{
			if (i->par->args[0] != NULL)
				argv_export(i);
			else
				ft_export(i);
		}
		else
		{
			i->status = 127;
			ft_error_msg(i, 0);
		}
	}
	else if (b_check_mayus(i->par->cmd, "echo"))
		ft_echo(i, i->par->args);
	else
		ft_builtins3(i);
}

void	ft_builtins(t_info *i)
{
	if (b_check_mayus(i->par->cmd, "pwd"))
		ft_pwd(i->c);
	else if (b_check_mayus(i->par->cmd, "env"))
	{
		if (i->par->args[0] != NULL)
			env_argv(i);
		else
			ft_env(i);
	}
	else if (b_check_mayus(i->par->cmd, "unset"))
	{
		if (ft_strcmp(i->par->cmd, "unset"))
		{
			i->status = 127;
			ft_error_msg(i, 0);
		}
		else
			ft_unset(i);
	}
	else
		ft_builtins2(i);
	if (i->n_cmds > 1 && !b_check_mayus(i->par->cmd, "exit"))
		exit(i->status);
}
