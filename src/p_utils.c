/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:27:49 by palucena          #+#    #+#             */
/*   Updated: 2023/11/24 13:37:06 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_heredoc(char *limiter)
{
	pid_t	pid;
	char	*str;
	int		fd[2];

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		g_signal_detector = HEREDOC;
		close(fd[0]);
		while (1)
		{
			str = readline("> ");
			if (!str || !ft_strncmp(str, limiter, ft_strlen(str)))
				exit(0);
			ft_putstr_fd(str, fd[1]);
			ft_putstr_fd("\n", fd[1]);
			free(str);
		}
	}
	g_signal_detector = HEREDOC_DAD;
	waitpid(-1, NULL, 0);
	close(fd[1]);
	return (fd[0]);
}

int	p_open(t_lx *lex)
{
	int	fd;

	fd = -1;
	if (lex->next && lex->token == REDIR_IN)
		fd = open(lex->next->content, 0444);
	else if (lex->next && lex->token == REDIR_OUT)
		fd = open(lex->next->content, O_CREAT | O_RDWR | O_TRUNC, 0666);
	else if (lex->next && lex->token == REDIR_APPEND)
		fd = open(lex->next->content, O_CREAT | O_RDWR | O_APPEND, 0666);
	else if (lex->next && lex->token == REDIR_HEREDOC)
	{
		fd = ft_heredoc(lex->next->content);
		if (g_signal_detector != CANCEL_EXEC)
			g_signal_detector = BASE;
	}
	return (fd);
}

t_lx	*p_fill_arg(char **args, t_lx *lex)
{
	t_lx	*curr;
	int		i;

	curr = lex;
	i = -1;
	while (curr && curr->token != PIPE)
	{
		if (curr->token == ARG)
			args[++i] = ft_strdup(curr->content);
		curr = curr->next;
	}
	args[++i] = NULL;
	return (lex);
}

int	ft_count_nodes(t_ps *par)
{
	t_ps	*curr;
	int		i;

	i = 0;
	curr = par;
	while (curr)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}
