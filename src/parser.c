/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:09:51 by palucena          #+#    #+#             */
/*   Updated: 2023/10/26 20:06:00 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	p_add_back(t_ps **lst, t_ps *new)
{
	t_ps	*actual;

	if (*lst)
	{
		actual = *lst;
		while (actual->next)
			actual = actual->next;
		actual->next = new;
	}
	else
		*lst = new;
}

t_ps	*p_new_node(void)
{
	t_ps	*par;

	par = malloc(sizeof(par));
	par->next = NULL;
	return (par);
}

t_ps	*p_fill_ps(t_lx *lex)
{
	t_ps	*par;
	t_lx	*curr;
	int		i;

	curr = lex;
	i = 0;
	par = p_new_node();
	while (curr)
	{
		par->cmd[0] == curr->content;
		p_add_back(&par, p_new_node());
		while (curr && curr->token != PIPE);
			// rellena el nodo
	}
}
