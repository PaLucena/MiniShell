/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:37:45 by palucena          #+#    #+#             */
/*   Updated: 2023/11/24 11:35:34 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	l_check_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

bool	l_is_finished(char start, char curr)
{
	if (curr != ' ' && curr != 34 && curr != 39)
	{
		if (curr != '|' && curr != '<' && curr != '>' && start != '|'
			&& start != '<' && start != '>')
			return (false);
		else if (curr == start)
			return (false);
	}
	return (true);
}

int	l_check_tokens(t_lx *lex)
{
	t_lx	*curr;

	curr = lex;
	while (curr)
	{
		if (curr->token == -1)
			return (2);
		else if (curr->next && curr->token >= 3 && curr->token <= 6
			&& curr->next->token >= 2 && curr->next->token <= 6)
			return (curr->next->token);
		if (!curr->next)
			break ;
		curr = curr->next;
	}
	if (curr->token >= 2 && curr->token <= 6)
		return (7);
	return (0);
}

bool	l_check_syntax(char *str, t_info *info)
{
	if (str[0] == '|' && str[1] == '|')
	{
		ft_error_msg(info, 2);
		return (false);
	}
	else if (str[0] == '<' && str[1] && str[2] && str[2] == str[0])
	{
		ft_error_msg(info, 3);
		return (false);
	}
	else if (str[0] == '>' && str[1] && str[2] && str[2] == str[0])
	{
		ft_error_msg(info, 4);
		return (false);
	}
	return (true);
}
