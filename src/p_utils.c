/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:27:49 by palucena          #+#    #+#             */
/*   Updated: 2023/11/23 19:18:54 by palucena         ###   ########.fr       */
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
	g_signal_detector = HEREDOC;
	if (pid == 0)
	{
		close(fd[0]);
		while (1)
		{
			str = readline("> ");
			if (!str)
				str = ft_strjoin(limiter, "\n");
			if (ft_strncmp(str, limiter, ft_strlen(str)) == 10)
				exit(0);
			ft_putstr_fd(str, fd[1]);
			free(str);
		}
	}
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
