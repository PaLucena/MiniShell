/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_next.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:09:02 by palucena          #+#    #+#             */
/*   Updated: 2023/11/25 20:56:52 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	l_end_of_word(char *str, int i);

static int	l_end_of_quote(char *str, int i)
{
	int	j;

	j = i;
	i++;
	while (str[i] && str[i] != str[j])
		i++;
	i++;
	if (str[i] && (str[i] == 34 || str[i] == 39))
		i = l_end_of_quote(str, i);
	else if (str[i] && str[i] != ' ' && str[i] != '|'
		&& str[i] != '<' && str[i] != '>')
		i = l_end_of_word(str, i);
	return (i);
}

static int	l_end_of_word(char *str, int i)
{
	if (str[i] == '<')
	{
		while (str[i] == '<')
			i++;
		return (i);
	}
	else if (str[i] == '>')
	{
		while (str[i] == '>')
			i++;
		return (i);
	}
	else if (str[i] == '|')
		i++;
	while (str[i] && str[i] != ' ' && str[i] != '|' && str[i] != 34
		&& str[i] != 39 && str[i] != '<' && str[i] != '>')
		i++;
	if (str[i] && (str[i] == 34 || str[i] == 39))
		i = l_end_of_quote(str, i);
	return (i);
}

int	l_get_next_i(char *str, int i)
{
	if (str[i] == '|' && str[i + 1] != ' ')
		return (i + 1);
	if (str[i] && (str[i] == 34 || str[i] == 39))
		i = l_end_of_quote(str, i);
	else if (str[i])
		i = l_end_of_word(str, i);
	while (str[i] && str[i] == ' ')
		i++;
	return (i);
}
