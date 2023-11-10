/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:09:51 by palucena          #+#    #+#             */
/*   Updated: 2023/11/10 14:42:07 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ps	*p_new_node(t_ps *par, t_lx *lex)
{
	t_ps	*new;
	t_lx	*rot;
	int		i;

	i = 0;
	rot = lex;
	new = malloc(sizeof(t_ps));
	new->infile = 0;
	new->outfile = 1;
	while (rot && rot->token != PIPE)
	{
		if (rot->token == ARG)
		{
			while (rot && rot->token != PIPE)
			{
				if (rot->token == ARG)
					i++;
				rot = rot->next;
			}
			break ;
		}
		rot = rot->next;
	}
	new->args = malloc(sizeof(char *) * (i + 1));
	new->args[i] = NULL;
	new->next = NULL;
	if (par)
		par->next = new;
	return (new);
}

int	ft_heredoc(char *limiter)
{
	pid_t	pid;
	char	*str;
	int		fd[2];

	(void)limiter;
	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		while (1)
		{
			write(1, "> ", 2);
			str = get_next_line(0);
			if (ft_strncmp(str, limiter, ft_strlen(str)) == 10)
				exit(0);
			ft_putstr_fd(str, fd[1]);
			free(str);
		}
	}
 	else
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
		fd = ft_heredoc(lex->next->content);
	return (fd);
}

t_lx	*p_fill_arg(t_lx *lex, t_ps *par)
{
	int	i;

	i = -1;
	while (lex && lex->token == ARG)
	{
		par->args[++i] = ft_strdup(lex->content);
		lex = lex->next;
	}
	par->args[++i] = NULL;
	return (lex);
}

t_ps	*p_fill_ps(t_lx *lex, t_ps *par)
{
	t_ps	*curr;
	int		fd[2];

	curr = p_new_node(NULL, lex);
	par = curr;
	while (lex)
	{
		if (lex->token == REDIR_IN || lex->token == REDIR_HEREDOC)
			curr->infile = p_open(lex);
		else if (lex->token == REDIR_OUT || lex->token == REDIR_APPEND)
			curr->outfile = p_open(lex);
		else if (lex->token == CMD)
			curr->cmd = ft_strdup(lex->content);
		if (lex->token == ARG)
			lex = p_fill_arg(lex, curr);
		else if (lex && lex->token == PIPE)
		{
			lex = lex->next;
			pipe(fd);
			if (curr->outfile == 1)
				curr->outfile = fd[1];
			curr = p_new_node(curr, lex);
			curr->infile = fd[0];
		}
		else if (lex)
			lex = lex->next;
		else
			break ;
	}
	return (par);
}
