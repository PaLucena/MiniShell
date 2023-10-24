/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:45:41 by palucena          #+#    #+#             */
/*   Updated: 2023/10/24 22:28:58 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**l_split(char *input)
{
	char	**words;
	int		i;
	int		j;

	words = malloc(sizeof(char *) * (l_count_words(input) + 1));
	if (words == NULL)
		return (NULL);
	i = -1;
	j = -1;
	while (input[++i])
	{
		if (input[i] == 34 || input[i] == 39)
		{
			words[++j] = l_fill_quote(input, i);
			i = l_end_of_quote(input, i);
		}
		else if (input[i] && input[i] != ' ')
		{
			words[++j] = l_fill_word(input, i);
			i += ft_strlen(words[j]);
		}
		i = l_skip_space(input, i);
	}
	words[++j] = NULL;
	return (words);
}

t_lx	*ft_lexer(char *input)
{
	char	**words;
	t_lx	*lex;

	if (l_count_words(input) == -1)
	{
		printf("Close the quote!\n");
		return (0);
	}
	words = l_split(input);
	lex = l_tokenkizer(words);
	return (lex);
}
