/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:09:51 by palucena          #+#    #+#             */
/*   Updated: 2023/11/05 22:41:51 by palucena         ###   ########.fr       */
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
	new->infile = -1;
	new->outfile = 1;
	while (rot && rot->token != PIPE)
	{
		if (rot->token == CMD)
			new->cmd = malloc(sizeof(char) * (ft_strlen(rot->content) + 1));
		if (rot->token == ARG)
		{
			while (rot && rot->token == ARG)
			{
				rot = rot->next;
				i++;
			}
			break ;
		}
		if (rot)
			rot = rot->next;
	}
	new->args = malloc(sizeof(char *) * (i + 1));
	new->args[i] = NULL;
	new->next = NULL;
	if (par)
		par->next = new;
	return (new);
}

int	p_open(t_lx *lex)
{
	int	fd;

	fd = -2;
	if (lex->next && lex->token == REDIR_IN)
		fd = open(lex->next->content, 0444);
	else if (lex->next && lex->token == REDIR_OUT)
		fd = open(lex->next->content, O_CREAT | O_RDWR | O_TRUNC, 0777);
	else if (lex->next && lex->token == REDIR_APPEND)
		fd = open(lex->next->content, O_CREAT | O_RDWR | O_APPEND, 0777);
	return (fd);
}

t_lx	*p_fill_arg(t_lx *lex, t_ps *par)
{
	int	i;

	i = -1;
	while (lex && lex->token == ARG)
	{
		par->args[++i] = malloc(sizeof(char) * (ft_strlen(lex->content) + 1));
		par->args[i] = ft_strdup(lex->content);
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
		if (lex->token == REDIR_IN)
			curr->infile = p_open(lex);
		else if (lex->token == REDIR_OUT || lex->token == REDIR_APPEND)
			curr->outfile = p_open(lex);
		else if (lex->token == REDIR_HEREDOC)
			curr->infile = 0;
		else if (lex->token == CMD)
			curr->cmd = ft_strdup(lex->content);
		if (lex->token == ARG)
			lex = p_fill_arg(lex, curr);
		else if (lex && lex->token == PIPE)
		{
			lex = lex->next;
			pipe(fd);
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
