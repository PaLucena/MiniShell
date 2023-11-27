/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:16:17 by palucena          #+#    #+#             */
/*   Updated: 2023/11/27 18:37:02 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_path(t_env *env, char *cmd)
{
	t_env	*curr;
	char	**path;
	char	*new_path;
	char	*aux;
	int		i;

	curr = env;
	while (curr && ft_strcmp(curr->key, "PATH") != 0)
		curr = curr->next;
	if (!curr)
		exit (127);
	path = ft_split(curr->value, ':');
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
	return (cmd);
}

static char	**ft_new_env(t_env *list_env)
{
	char	**new_env;
	char	*aux;
	t_env	*curr;
	int		i;

	i = 0;
	curr = list_env;
	while (curr)
	{
		i++;
		curr = curr->next;
	}
	new_env = malloc(sizeof(char *) * (i + 1));
	curr = list_env;
	i = -1;
	while (curr)
	{
		aux = ft_strjoin(curr->key, "=");
		new_env[++i] = ft_strjoin(aux, curr->value);
		curr = curr->next;
		free(aux);
	}
	new_env[++i] = NULL;
	return (new_env);
}

void	exec_cmd(t_info *info)
{
	char	**cmd_arg;
	char	*cmd_path;
	int		i;

	if (info->par->infile != 0)
		dup2(info->par->infile, STDIN_FILENO);
	if (info->par->outfile != 1)
		dup2(info->par->outfile, STDOUT_FILENO);
	if (ft_isalnum(info->par->cmd[0]))
		cmd_path = find_path(info->c->list_env, info->par->cmd);
	else
		cmd_path = ft_strdup(info->par->cmd);
	i = 0;
	while (info->par->args[i])
		i++;
	cmd_arg = malloc(sizeof(char *) * (i + 2));
	i = -1;
	cmd_arg[0] = info->par->cmd;
	while (info->par->args[++i])
		cmd_arg[i + 1] = info->par->args[i];
	cmd_arg[i + 1] = NULL;
	execve(cmd_path, cmd_arg, ft_new_env(info->c->list_env));
	exit (127);
}

static void	ft_next_cmd(t_info *info)
{
	t_ps	*aux;

	if (info->par->infile != 0)
		close(info->par->infile);
	if (info->par->outfile != 1)
		close(info->par->outfile);
	aux = info->par;
	info->par = info->par->next;
	free(aux->cmd);
	ft_free(aux->args);
	free(aux);
}

void	ft_execute(t_info *info)
{
	pid_t	pid;

	while (info->par)
	{
		if (check_builtin(info->par->cmd) && info->n_cmds == 1)
			ft_builtins(info);
		else
		{
			g_signal_detector = MID_CMD;
			pid = fork();
			if (pid == 0)
			{
				if (check_builtin(info->par->cmd))
					ft_builtins(info);
				else
					exec_cmd(info);
			}
			else
				waitpid(-1, &info->status, 0);
			ft_error_msg(info, 0);
			g_signal_detector = BASE;
		}
		ft_next_cmd(info);
	}
}
