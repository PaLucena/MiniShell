/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_start.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:09:51 by palucena          #+#    #+#             */
/*   Updated: 2023/11/13 15:43:15 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	p_add_args(t_lx *lex, t_ps *par)
{
	t_lx	*curr;
	int		i;
	int		j;

	curr = lex;
	i = 0;
	while (curr && curr->token != PIPE)
	{
		if (curr->token == ARG)
		{
			while (curr && curr->token != PIPE)
			{
				if (curr->token == ARG)
					i++;
				curr = curr->next;
			}
			break ;
		}
		curr = curr->next;
	}
	par->args = malloc(sizeof(char *) * (i + 1));
	j = -1;
	while (++j <= i)
		par->args[j] = NULL;
}

t_ps	*p_new_node(t_ps *par, t_lx *lex)
{
	t_ps	*new;

	new = malloc(sizeof(t_ps));
	new->infile = 0;
	new->outfile = 1;
	p_add_args(lex, new);
	new->next = NULL;
	if (par)
		par->next = new;
	return (new);
}

static void	p_fill_content(t_ps *par, t_lx *lex)
{
	if (lex->token == REDIR_IN || lex->token == REDIR_HEREDOC)
		par->infile = p_open(lex);
	else if (lex->token == REDIR_OUT || lex->token == REDIR_APPEND)
		par->outfile = p_open(lex);
	else if (lex->token == CMD)
		par->cmd = ft_strdup(lex->content);
	else if (lex->token == ARG && !par->args[0])
		p_fill_arg(par->args, lex);
}

t_ps	*p_fill_ps(t_lx *lex, t_ps *par)
{
	t_ps	*curr;
	int		fd[2];

	curr = p_new_node(NULL, lex);
	par = curr;
	while (lex)
	{
		p_fill_content(curr, lex);
		if (lex && lex->token == PIPE)
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
