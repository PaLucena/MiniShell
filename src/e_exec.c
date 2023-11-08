
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

char	*find_path(char **path, char *cmd)
{
	char	*new_path;
	char	*aux;
	int		i;

	i = -1;
	while (path[++i])
	{
		aux = ft_strjoin(path[i], "/");
		new_path = ft_strjoin(aux, cmd);
		free(aux);
		if (access(new_path, X_OK) == 0)
			return (new_path);
		free(new_path);
	}
	exit (1);
}

void	exec_cmd(t_info *info, char **envp)
{
	char	**cmd_arg;
	char	*cmd_path;
	int		i;

	if (info->par->infile != 0)
		dup2(info->par->infile, STDIN_FILENO);
	if (info->par->outfile != 0)
		dup2(info->par->infile, STDOUT_FILENO);
	cmd_path = find_path(info->c->path, info->par->cmd);
	i = 0;
	while (info->par->args[i])
		i++;
	cmd_arg = malloc(sizeof(char *) * (i + 2));
	i = -1;
	cmd_arg[0] = info->par->cmd;
	while (info->par->args[++i])
		cmd_arg[i + 1] = info->par->args[i];
	cmd_arg[i + 1] = NULL;
	execve(cmd_path, cmd_arg, envp);
}

void	ft_close(t_ps *par)
{
	if (par->infile != 0)
		close(par->infile);
	if (par->outfile != 1)
		close(par->outfile);
}

void	ft_execute(t_info *info, char **envp)
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
				exec_cmd(info, envp);
			else
				waitpid(-1, &info->status, 0);
		}
		ft_close(info->par);
		aux = info->par;
		info->par = info->par->next;
		free(aux->cmd);
		ft_free(aux->args);
	}
}
