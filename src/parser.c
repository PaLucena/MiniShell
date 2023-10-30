/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:09:51 by palucena          #+#    #+#             */
/*   Updated: 2023/10/30 00:59:37 by palucena         ###   ########.fr       */
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
	while (rot && rot->token != PIPE)
	{
		if (rot->token == CMD)
			new->cmd = malloc(sizeof(char) * (ft_strlen(rot->content) + 1));
		while (rot && rot->token == ARG)
		{
			rot = rot->next;
			i++;
		}
		new->args = malloc(sizeof(char *) * (i + 1));
		if (rot)
			rot = rot->next;
	}
	new->args[i] = NULL;
	if (par)
		par->next = new;
	return (new);
}

int	p_open(t_lx *lex)
{
	int	fd;

	fd = -1;
	if (lex->next && lex->token == REDIR_FILEIN)
		fd = open(lex->next->content, 0444);
	else if (lex->next && lex->token == REDIR_FILEOUT)
		fd = open(lex->next->content, 0777, O_TRUNC);
	else if (lex->next)
		fd = open(lex->next->content, 0777, O_APPEND);
	return (fd);
}

t_lx	*p_fill_arg(t_lx *lex, t_ps *par)
{
	int	i;

	i = 0;
	while (lex && lex->token == ARG)
		par->args[i++] = ft_strdup(lex->content);
	par->args[i] = NULL;
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
		if (lex->token == REDIR_FILEIN)
			curr->infile = p_open(lex);
		else if (lex->token == REDIR_FILEOUT || lex->token == REDIR_APPEND)
			curr->outfile = p_open(lex);
		else if (lex->token == CMD)
			curr->cmd = lex->content;
		else if (lex->token == ARG)
			lex = p_fill_arg(lex, curr);
		else if (lex->token == PIPE)
		{
			pipe(fd);
			curr->outfile = fd[1];
			curr = p_new_node(curr, lex);
			curr->infile = fd[0];
		}
		lex = lex->next;
	}
	return (par);
}
