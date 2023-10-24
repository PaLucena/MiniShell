/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_token.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:30:18 by palucena          #+#    #+#             */
/*   Updated: 2023/10/24 19:52:35 by palucena         ###   ########.fr       */
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

int	l_get_token(char **words, int i)
{
	if (ft_strcmp(words[i], "|"))
		return (PIPE);
	else if (l_check_redir(words[i]) != 0)
		return (l_check_redir(words[i]));
	else if (i == 0 || ft_strcmp(words[i - 1], "|"))
		return (CMD);
	else if (ft_strcmp(words[i - 1], "<"))
		return (REDIR_FILEIN);
	else if (ft_strcmp(words[i - 1], ">") || ft_strcmp(words[i - 1], ">>"))
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

t_lx	*l_tokenkizer(char **words)
{
	t_lx 	*lex;
	t_lx	*curr;
	int		i;

	lex = malloc(sizeof(t_lx));
	i = 0;
	lex->content = words[i];
	lex->token = l_get_token(words, i);
	lex->next = NULL;
	while (words[++i])
	{
		curr = malloc(sizeof(t_lx));
		curr->content = words[i];
		curr->token = l_get_token(words, i);
		curr->next = NULL;
		l_lxadd_back(&lex, curr);
	}
	//no
	curr = lex;
	while (curr)
	{
		printf("%s %i\n", curr->content, (int)curr->token);
		curr = curr->next;
	}
	//no
	return (lex);
}
