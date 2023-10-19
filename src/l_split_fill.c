/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_split_fill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:21:49 by palucena          #+#    #+#             */
/*   Updated: 2023/10/19 14:18:10 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*l_fill_quote(char *input, int start)
{
	char	*word;
	int		end;
	int		i;

	end = l_end_of_quote(input, start);
	word = malloc(sizeof(char) * (end - start + 1));
	i = 0;
	while (start < end)
	{
		word[i]  = input[start];
		start++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	*l_fill_word(char *input, int start)
{
	char	*word;
	int		end;
	int		i;

	end = start;
	while (input[end] && input[end] != ' ')
		end++;
	word = malloc(sizeof(char) * (end - start + 1));
	i = 0;
	while (start < end)
	{
		word[i] = input[start];
		start++;
		i++;
	}
	word[i] = '\0';
	return (word);
}
