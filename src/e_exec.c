
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:16:17 by palucena          #+#    #+#             */
/*   Updated: 2023/11/08 00:44:11 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_cmd(t_ps *par)
{
	
}

void	ft_close(t_ps *par)
{
	if (par->infile != 0)
		close(par->infile);
	if (par->outfile != 1)
		close(par->outfile);
}

void	ft_execute(t_info *info)
{
	pid_t	pid;
	int		status;

	while (info->par)
	{
		pid = fork();
		if (pid == 0)
		{
			if (check_builtin(info->par->cmd))
				ft_printf("Todavia no tengo built-ins 😭\n");
			//	ft_builtins(info->c, info->par->args, i);
			//	exit (0);
			else
				exec_cmd(info->par);
		}
		else
		{
			waitpid(-1, &status, 0);
			if (status != 0)
				printf("Algo anda mal\n");
		}
		ft_close(info->par);
		info->par = info->par->next;
	}
}
