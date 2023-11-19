/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_token.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:30:18 by palucena          #+#    #+#             */
/*   Updated: 2023/11/19 21:24:47 by palucena         ###   ########.fr       */
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

int	l_get_token(char *actual, t_lx *prev, bool check)
{
	static bool	cmd_door = false;

	if (check)
		cmd_door = true;
	if (ft_strcmp(actual, "|") == 0)
	{
		cmd_door = false;
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

int	l_check_tokens(t_lx *lex)
{
	t_lx	*curr;

	curr = lex;
	while (curr)
	{
		if (curr->token == -1)
			return (-1);
		else if (curr->next && curr->token >= 3 && curr->token <= 6
			&& curr->next->token >= 2 && curr->token <= 6)
			return (3);
		else if (curr->content[0] && curr->content[0] == '|'
			&& curr->content[1] == '|')
			return (0);
		else if (curr->content[0] && curr->content[1] && curr->content[2]
			&& ((curr->content[0] == '<' && curr->content[2] == '<')
			|| (curr->content[0] == '>' && curr->content[2] == '>')))
			return (3);
		if (!curr->next)
			break ;
		curr = curr ->next;
	}
	if (curr->token >= 2 && curr->token <= 6)
		return (curr->token);
	return (0);
}
	// Me he pasado de frenada con las redirecciones

int	l_tokenizer(t_lx *lex, int i)
{
	bool	cmd_door;
	t_lx	*curr;
	t_lx	*prev;

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
	while (curr)
	{
		curr->token = l_get_token(curr->content, prev, cmd_door);
		cmd_door = false;
		prev = curr;
		curr = curr->next;
		i++;
	}
	return (l_check_tokens(lex));
}
