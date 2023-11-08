/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:01:12 by palucena          #+#    #+#             */
/*   Updated: 2023/11/08 14:32:05 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free(char **str)
{
	char	**ptr;

	if (!str)
		return ;
	ptr = str;
	while (*ptr)
	{
		free(*ptr);
		ptr++;
	}
	free(str);
}

void	free_lexer(t_lx *lex)
{
	t_lx	*curr;

	while (lex)
	{
		curr = lex;
		lex = curr->next;
		free(curr->content);
		free(curr);
	}
}

void	free_parser(t_ps *par)
{
	t_ps	*curr;

	while (par)
	{
		curr = par;
		par = curr->next;
		free(curr->cmd);
		ft_free(curr->args);
		free(curr);
	}
}
