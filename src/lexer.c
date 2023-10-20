/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:45:41 by palucena          #+#    #+#             */
/*   Updated: 2023/10/20 15:12:09 by palucena         ###   ########.fr       */
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
	}
	words[++j] = NULL;
	return (words);
}

void	l_tokenkizer(t_lx *lex, char **words)
{
	t_lx	*curr;
	int		i;

	curr = lex;
	i = 0;
	while (words[i]) /// esto no va asi
	{
		curr->content = words[i];
		curr->token = l_get_token(words, i);
		if (words[i + 1])
			curr = curr->next;
		i++;
	}
	curr->next = NULL;
	//no
	curr = lex;
	while (curr->next)
	{
		printf("%s %i\n", curr->content, (int)curr->token);
		curr = curr->next;
	}
	//no
}

int	ft_lexer(t_lx *lex, char *input)
{
	char	**words;
	int		i;

	(void)lex;
	if (l_count_words(input) == -1)
	{
		printf("Close the quote!\n");
		return (0);
	}
	words = l_split(input);
	l_tokenkizer(lex, words);
/* 	i = -1;
	while (words[++i]) 				// Esto
		printf("%s\n", words[i]);	// no */
	i = 0;
	return (0);
}
