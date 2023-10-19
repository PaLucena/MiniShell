/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_split.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:34:10 by palucena          #+#    #+#             */
/*   Updated: 2023/10/19 14:18:40 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	l_end_of_quote(char *str, int start)
{
	int	i;

	i = start + 1;
	while (str[i] != str[start])
		i++;
	if (str[i] == 0)
		return (-1);
	return (i);
}

int	l_count_words(char *str)
{
	int	i;
	int	n_words;

	i = 0;
	n_words = 0;
	while (str[i])
	{
		if (str[i] == 34 || str[i] == 39)
		{
			i = l_end_of_quote(str, i);
			if (i == -1)
				return (-1);
			n_words++;
		}
		else if (str[i] != ' ')
		{
			while (str[i] && str[i] != ' ')
				i++;
			n_words++;
		}
		i++;
	}
	return (n_words);
}

char	**l_split(char *input)
{
	char	**words;
	int		i;
	int		j;

	words = malloc(sizeof(char *) * (l_count_words(input) + 1));
	if (words == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (input[++i])
	{
		if (input[i] == 34 || input[i] == 39)
		{
			words[j] = l_fill_quote(input, i);
			j++;
		}
		else if (input[i] && input[i] != ' ')
		{
			words[j] = l_fill_word(input, i);
			i += ft_strlen(words[j]);
			j++;
		}
	}
	words[j] = NULL;
	return (words);
}
