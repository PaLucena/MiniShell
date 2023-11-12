/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_lexer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:45:41 by palucena          #+#    #+#             */
/*   Updated: 2023/11/11 19:25:44 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lx	*l_new_node(char *str, int i, t_env *env)
{
	t_lx	*lex;

	lex = malloc(sizeof(t_lx));
	lex->content = l_get_content(str, i, env);
	lex->next = NULL;
	return (lex);
}

char	*l_get_quote(char *str, int start, t_env *env)
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
	if (l_is_env(quote, env) && str[start] != 39)
		quote = l_get_env(quote, env);
	if (str[++i] && str[i] != ' ')
	{
		if (str[i] == 34 || str[i] == 39)
			aux = l_get_quote(str, i, env);
		else
			aux = l_get_word(str, i, env);
		mix = ft_strjoin(quote, aux);
		free(quote);
		free(aux);
		return (mix);
	}
	return (quote);
}

char	*l_get_word(char *str, int start, t_env *env)
{
	char	*word;
	char	*aux;
	char	*mix;
	int		i;

	i = start;
	while (str[i] && str[i] != ' ' && str[i] != 34 && str[i] != 39)
		i++;
	word = ft_substr(str, start, i - start);
	if (l_is_env(word, env))
		word = l_get_env(word, env);
	if (str[i] == 34 || str[i] == 39)
	{
		aux = l_get_quote(str, i, env);
		mix = ft_strjoin(word, aux);
		free(word);
		free(aux);
		return (mix);
	}
	return (word);
}

char	*l_get_content(char *input, int i, t_env *env)
{
	while (input[i] == ' ')
		i++;
	if (input[i] && (input[i] == 34 || input[i] == 39))
		return (l_get_quote(input, i, env));
	else if (input[i])
		return (l_get_word(input, i, env));
	return (NULL);
}

t_lx	*l_fill_lx(char *input, t_env *env)
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
		if (lex == NULL && input[i])
			lex = l_new_node(input, i, env);
		else if (input[i])
			l_add_back(&lex, l_new_node(input, i, env));
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
