/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_start.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:45:41 by palucena          #+#    #+#             */
/*   Updated: 2023/11/24 15:40:48 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lx	*l_new_node(char *str, int i, t_info *info)
{
	t_lx	*lex;

	lex = malloc(sizeof(t_lx));
	lex->content = l_get_content(str, i, info);
	if (!lex->content)
		return (NULL);
	lex->next = NULL;
	return (lex);
}

char	*l_get_quote(char *str, int start, t_info *info)
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
	if (str[start] != 39)
		quote = l_get_env(quote, info);
	if (str[++i] && str[i] != ' ')
	{
		if (str[i] == 34 || str[i] == 39)
			aux = l_get_quote(str, i, info);
		else
			aux = l_get_word(str, i, info);
		mix = ft_strjoin(quote, aux);
		free(quote);
		free(aux);
		return (mix);
	}
	return (quote);
}

char	*l_get_word(char *str, int start, t_info *info)
{
	char	*word;
	char	*aux;
	char	*mix;
	int		i;

	i = start + 1;
	while (str[i] && !l_is_finished(str[start], str[i]))
		i++;
	word = ft_substr(str, start, i - start);
	word = l_get_env(word, info);
	if (!l_check_syntax(word, info))
		return (NULL);
	if (str[i] == 34 || str[i] == 39)
	{
		aux = l_get_quote(str, i, info);
		mix = ft_strjoin(word, aux);
		free(word);
		free(aux);
		return (mix);
	}
	return (word);
}

char	*l_get_content(char *input, int i, t_info *info)
{
	while (input[i] == ' ')
		i++;
	if (input[i] && (input[i] == 34 || input[i] == 39))
		return (l_get_quote(input, i, info));
	else if (input[i])
		return (l_get_word(input, i, info));
	return (NULL);
}

t_lx	*l_fill_lx(char *input, t_info *info)
{
	t_lx	*curr;
	t_lx	*lex;
	int		i;

	i = 0;
	lex = NULL;
	while (input[i] == ' ')
		i++;
	while (input[i])
	{
		if (lex == NULL && input[i])
			lex = l_new_node(input, i, info);
		else if (input[i])
			l_add_back(&lex, l_new_node(input, i, info));
		i = l_get_next_i(input, i);
		if (!curr)
			return (NULL);
		curr = lex;
	}
	if (l_tokenizer(lex) != 0)
	{
		ft_error_msg(info, l_check_tokens(lex));
		return (NULL);
	}
	return (lex);
}
