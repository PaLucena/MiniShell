/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_shell_level.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:17:09 by rdelicad          #+#    #+#             */
/*   Updated: 2023/11/20 20:23:41 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell_level_detected(t_info *i, char *input)
{
	char	*tmp;

	tmp = NULL;
	tmp = ft_strrchr(input, '/');
	if (!tmp)
		tmp = input;
	if (ft_strcmp(input, "./minishell") == 0 || ft_strcmp(tmp, "minishell") == 0)
		shell_level_up(i);
	/* else
		shell_level_down(i); */
}

void	shell_level_up(t_info *i)
{
	t_env	*curr;
	char	*tmp;
	int		level;

	level = 1;
	curr = i->c->list_env;
	while (ft_strcmp(curr->key, "SHLVL") != 0)
		curr = curr->next;
	if (!curr)
		return ;
	level = ft_atoi(curr->value);
	level++;
	tmp = ft_itoa(level);
	free(curr->value);
	curr->value = tmp;
	free(tmp);
}

void	shell_level_down(t_info *i)
{
	t_env	*curr;
	char	*tmp;
	int		level;

	curr = i->c->list_env;
	while (ft_strcmp(curr->key, "SHLVL") != 0)
		curr = curr->next;
	if (!curr)
		return ;
	level = ft_atoi(curr->value);
	level--;
	tmp = ft_itoa(level);
	free(curr->value);
	curr->value = tmp;
	free(tmp);
}
