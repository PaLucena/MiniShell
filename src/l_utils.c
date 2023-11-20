/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:37:45 by palucena          #+#    #+#             */
/*   Updated: 2023/11/20 17:36:19 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	l_get_next_i(char *str, int i)
{
	int	j;

	j = i;
	if (str[i] == 34 || str[i] == 39 || str[i] == '|'
		|| str[i] == '>' || str[i] =='<')
		i++;
	else if (str[i] && str[i] == ' ')
	{
		while (str[i] == ' ')
			i++;
	}
	while (str[i] && !l_is_finished(str[j], str[i]))
		i++;
	return (i);
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
	// Comprobar si:
	// - Hay >>> o <<<
	// - Hay ||
	// Mandar a imprimir el error que sea y return (false)
	if (str[0] == '|' && str[1] == '|')
	{
		ft_error_msg(info, 2);
		return (false);
	}
	else if (str[0] == '<' && str[2] && str[2] == str[0])
	{
		ft_error_msg(info, 3);
		return (false);
	}
	else if (str[0] == '>' && str[2] && str[2] == str[0])
	{
		ft_error_msg(info, 4);
		return (false);
	}
	return (true);
}
