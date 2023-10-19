/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:45:41 by palucena          #+#    #+#             */
/*   Updated: 2023/10/19 13:30:24 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lexer(t_lx **lex, char *input)
{
	char	**words;
	int		i;

	(void)lex;
	words = l_split(input);
	i = -1;
	while (words[++i])
		printf("%s\n", words[i]);
	if (!words)
		return (-1);
	i = 0;
	return (0);
}
