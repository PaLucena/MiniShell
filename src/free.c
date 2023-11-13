/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:01:12 by palucena          #+#    #+#             */
/*   Updated: 2023/11/13 19:03:14 by palucena         ###   ########.fr       */
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

void	free_info(t_info *info)
{
	//rl_clear_history();
	ft_free_list(info->c->list_env);
	ft_matfree(info->c->path);
	free(info->c);
	free(info);
}
