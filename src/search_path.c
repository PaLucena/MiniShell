/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:48:25 by rdelicad          #+#    #+#             */
/*   Updated: 2023/11/16 18:01:26 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	search_path(t_info *i)
{
	t_env	*curr;

	curr = i->c->list_env;
	while (curr)
	{
		if (ft_strcmp(curr->key, "PATH") != 0)
			return (0);
	}
	return (1);
}
