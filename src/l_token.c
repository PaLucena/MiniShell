/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_token.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:30:18 by palucena          #+#    #+#             */
/*   Updated: 2023/10/25 00:45:02 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	l_check_redir(char *word)
{
	if (ft_strcmp(word, "<"))
		return (REDIR_IN);
	else if (ft_strcmp(word, ">"))
		return (REDIR_OUT);
	else if (ft_strcmp(word, "<<"))
		return (REDIR_HEREDOC);
	else if (ft_strcmp(word, ">>"))
		return (REDIR_APPEND);
	return (0);
}

int	l_get_token(char *actual, char *prev, int i)
{
	if (i == 0 || ft_strcmp(prev, "|"))
		return (CMD);
	else if (ft_strcmp(actual, "|"))
		return (PIPE);
	else if (l_check_redir(actual) != 0)
		return (l_check_redir(actual));
	else if (ft_strcmp(prev, "<"))
		return (REDIR_FILEIN);
	else if (ft_strcmp(prev, ">") || ft_strcmp(prev, ">>"))
		return (REDIR_FILEOUT);
	else
		return (ARG);
}

void	l_lxadd_back(t_lx **lst, t_lx *new)
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

t_lx	*l_new_node(char *str, int i)
{
	t_lx	*lex;

	lex = malloc(sizeof(t_lx));
	lex->content = l_get_content(str, i);
	lex->next = NULL;
	return (lex);
}

void	l_tokenizer(t_lx *lex)
{
	t_lx	*curr;
	t_lx	*prev;
	int		i;

	curr = lex->next;
	prev = lex;
	prev->token = CMD;
	i = 1;
	while (curr)
	{
		curr->token = l_get_token(curr->content, prev->content, i);
		prev = curr;
		curr = curr->next;
		i++;
	}
}
