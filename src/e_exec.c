
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
	(void)par;
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
	t_ps	*aux;
	pid_t	pid;

	while (info->par)
	{
		if (info->exit)
			break;
		if (check_builtin(info->par->cmd))
			ft_builtins(info);
		//	ft_printf("Todavia no tengo built-ins 😭\n");
		else
		{
			pid = fork();
			if (pid == 0)
				exec_cmd(info->par);
			else
				waitpid(-1, info->status, 0);
		}
		ft_close(info->par);
		aux = info->par;
		info->par = info->par->next;
		free(aux->cmd);
		ft_free(aux->args);
	}
}
