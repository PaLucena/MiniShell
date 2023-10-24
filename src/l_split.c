/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_split.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:34:10 by palucena          #+#    #+#             */
/*   Updated: 2023/10/24 22:35:57 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	l_skip_space(char *str, int i)
{
	if (str[i] != ' ')
		i++;
	while (str[i] == ' ')
		i++;
	return (i);
}

int	l_end_of_quote(char *str, int start) // Esta funcion
{
	int	i;
	int	j;

	i = start + 1;
	j = 0;
	printf("Empieza: %i\n", i);
	while (str[i] && str[i] != str[start])
		i++;
	printf("??: %i\n", i);
	if (str[i] == 0)
		return (-1);
	if (start != 0 && str[start - 1] == ' ')
		return (i);
	return (i - 1);
}

int	l_count_words(char *str)
{
	int	i;
	int	n_words;

	i = 0;
	n_words = 0;
	while (str[i])
	{
		printf("Itera en: %i\n", i);
		if (str[i] == 34 || str[i] == 39)
		{
			i = l_end_of_quote(str, i) + 1;
			if (i == 0)
				return (-1);
			n_words++;
		}
		else if (str[i] != ' ')
		{
			while (str[i] && str[i] != ' ' && str[i] != 34 && str[i] != 39)
				i++;
			n_words++;
			i--;
		}
		i = l_skip_space(str, i);
	}
	return (n_words);
}

char	*l_fill_quote(char *input, int start)
{
	char	*word;
	int		i;
	int		j;

	word = malloc(sizeof(char) * (l_end_of_quote(input, start) - start + 3));
	i = 0;
	j = start;
	if (j != 0 && input[j - 1] == ' ')
	{
		word[0] = input[start];
		word[1] = input[start - 1];
		i = 2;
		j++;
	}
	word[i]  = input[j];
	while (input[++j] && input[j] != input[start])
		word[++i] = input[j];
	if (input[j])
		word[++i]  = input[j];
	word[++i] = '\0';
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
