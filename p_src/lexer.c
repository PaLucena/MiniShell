/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:45:41 by palucena          #+#    #+#             */
/*   Updated: 2023/11/08 01:24:25 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lx	*l_new_node(char *str, int i)
{
	t_lx	*lex;

	lex = malloc(sizeof(t_lx));
	lex->content = l_get_content(str, i);
	lex->next = NULL;
	return (lex);
}

char	*l_get_quote(char *str, int start)
{
	char	*quote;
	char	*aux;
	char	*mix;
	int		i;

	i = start + 1;
	while (str[i] && str[i] != str[start])
		i++;
	if (!str[i])
		return (NULL);
	quote = ft_substr(str, start + 1, i - (start + 1));
	if (str[++i] && str[i] != ' ')
	{
		if (str[i] == 34 || str[i] == 39)
			aux = l_get_quote(str, i);
		else
			aux = l_get_word(str, i);
		mix = ft_strjoin(quote, aux);
		free(quote);
		free(aux);
		return (mix);
	}
	return (quote);
}

char	*l_get_word(char *str, int start)
{
	char	*word;
	char	*aux;
	char	*mix;
	int		i;

	i = start;
	while (str[i] && str[i] != ' ' && str[i] != 34 && str[i] != 39)
		i++;
	word = ft_substr(str, start, i - start);
	if (str[i] == 34 || str[i] == 39)
	{
		aux = l_get_quote(str, i);
		mix = ft_strjoin(word, aux);
		free(word);
		free(aux);
		return (mix);
	}
	return (word);
}

char	*l_get_content(char *input, int i)
{
	while (input[i] == ' ')
		i++;
	if (input[i] && (input[i] == 34 || input[i] == 39))
		return (l_get_quote(input, i));
	else if (input[i])
		return (l_get_word(input, i));
	return (NULL);
}

t_lx	*l_fill_lx(char *input)
{
	t_lx	*curr;
	t_lx	*lex;
	int		i;

	i = 0;
	lex = NULL;
	while (input[i])
	{
		while (input[i] == ' ')
			i++;
		if (lex == NULL)
			lex = l_new_node(input, i);
		else
			l_add_back(&lex, l_new_node(input, i));
		curr = lex;
		while (curr->next)
			curr = curr->next;
		while (input[i] && input[i] != ' ')
			i++;
	}
	if (lex == NULL)
		return (0);
	l_tokenizer(lex);
	return (lex);
}
