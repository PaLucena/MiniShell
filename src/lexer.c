/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:45:41 by palucena          #+#    #+#             */
/*   Updated: 2023/10/26 17:22:20 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*l_get_quote(char *str, int start)
{
	char	*quote;
	int		i;

	i = start + 1;
	while (str[i] && str[i] != str[start])
		i++;
	if (!str[i])
		return (NULL);
	if (start != 0 && str[start - 1] == ' ')
		start--;
	quote = ft_substr(str, start, i - start + 1);
	if (quote[0] == ' ')
	{
		quote[0] = str[start + 1];
		quote[1] = str[start];
	}
	return (quote);
}

char	*l_get_word(char *str, int start)
{
	char	*word;
	int		i;

	i = start;
	while (str[i] && str[i] != ' ' && str[i] != 34 && str[i] != 39)
		i++;
	word = ft_substr(str, start, i - start);
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
			l_add_k(&lex, l_new_node(input, i));
		curr = lex;
		while (curr->next)
			curr = curr->next;
		i += ft_strlen(curr->content);
	}
	if (lex == NULL)
		return (0);
	l_tokenizer(lex);
	return (lex);
}
