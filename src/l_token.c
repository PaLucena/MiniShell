/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_token.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:30:18 by palucena          #+#    #+#             */
/*   Updated: 2023/10/31 00:04:05 by palucena         ###   ########.fr       */
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

int	l_get_token(char *actual, t_lx *prev, bool check)
{
	static bool	cmd_door = false;

	if (check)
		cmd_door = true;
	if (ft_strcmp(actual, "|"))
	{
		cmd_door = false;
		return (PIPE);
	}
	else if (l_check_redir(actual) != 0)
		return (l_check_redir(actual));
	else if (prev->token == REDIR_IN)
		return (REDIR_FILEIN);
	else if (prev->token == REDIR_OUT || prev->token == REDIR_APPEND)
		return (REDIR_FILEOUT);
	else if (!cmd_door)
	{
		cmd_door = true;
		return (CMD);
	}
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
	bool	cmd_door;
	t_lx	*curr;
	t_lx	*prev;
	int		i;

	curr = lex->next;
	prev = lex;
	cmd_door = false;
	if (l_check_redir(prev->content) == 0)
	{
		cmd_door = true;
		prev->token = CMD;
	}
	else
		prev->token = l_check_redir(prev->content);
	i = 1;
	while (curr)
	{
		curr->token = l_get_token(curr->content, prev, cmd_door);
		cmd_door = false;
		prev = curr;
		curr = curr->next;
		i++;
	}
}
