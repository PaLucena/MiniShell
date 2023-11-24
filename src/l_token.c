/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_token.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:30:18 by palucena          #+#    #+#             */
/*   Updated: 2023/11/24 13:55:30 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	l_check_redir(char *word)
{
	if (ft_strcmp(word, "<") == 0)
		return (REDIR_IN);
	else if (ft_strcmp(word, ">") == 0)
		return (REDIR_OUT);
	else if (ft_strcmp(word, "<<") == 0)
		return (REDIR_HEREDOC);
	else if (ft_strcmp(word, ">>") == 0)
		return (REDIR_APPEND);
	return (0);
}

static bool	l_search_cmd(t_lx *lex, int i)
{
	t_lx	*curr;
	int		c;

	curr = lex;
	c = 0;
	while (i > 0)
	{
		if (curr->token == CMD)
			c++;
		else if (curr->token == PIPE)
			c--;
		curr = curr->next;
		i--;
	}
	if (c != 0)
		return (false);
	return (true);
}

int	l_get_token(char *actual, t_lx *prev, t_lx *lex, int i)
{
	if (ft_strcmp(actual, "|") == 0)
	{
		if (prev->token == PIPE)
			return (-1);
		return (PIPE);
	}
	else if (l_check_redir(actual) != 0)
		return (l_check_redir(actual));
	else if (prev->token == REDIR_IN || prev->token == REDIR_HEREDOC)
		return (REDIR_FILEIN);
	else if (prev->token == REDIR_OUT || prev->token == REDIR_APPEND)
		return (REDIR_FILEOUT);
	else if (l_search_cmd(lex, i))
		return (CMD);
	else
		return (ARG);
}

void	l_add_back(t_lx **lst, t_lx *new)
{
	t_lx	*actual;

	if (*lst)
	{
		actual = *lst;
		while (actual->next)
			actual = actual->next;
		actual->next = new;
	}
	else
		*lst = new;
}

int	l_tokenizer(t_lx *lex)
{
	t_lx	*curr;
	t_lx	*prev;
	int		i;

	curr = lex->next;
	prev = lex;
	i = 1;
	prev->token = l_check_redir(prev->content);
	while (curr)
	{
		curr->token = l_get_token(curr->content, prev, lex, i);
		prev = curr;
		curr = curr->next;
		i++;
	}
	return (l_check_tokens(lex));
}
