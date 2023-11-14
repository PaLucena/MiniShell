/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils.cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:35:34 by rdelicad          #+#    #+#             */
/*   Updated: 2023/11/14 19:48:32 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_directory_path(t_info *i)
{
	i->c->curr = i->c->list_env;
	while (i->c->curr)
	{
		if ((ft_strcmp(i->c->curr->key, "HOME") == 0) && i->par->args[0] == 0)
			return (i->c->curr->value);
		else if (i->par->args[0] != NULL \
		&& (ft_strcmp(i->c->curr->key, "HOME") == 0)
			&& (ft_strcmp(i->par->args[0], "~") == 0))
			return (i->c->curr->value);
		else if (i->par->args[0] != NULL \
		&& (ft_strcmp(i->c->curr->key, "OLDPWD") == 0) \
		&& (ft_strcmp(i->par->args[0], "-") == 0))
			return (i->c->curr->value);
		else if (i->par->args[0] != NULL \
		&& ft_strcmp(i->par->args[0], "/") == 0)
			return ("/");
		else if (i->par->args[0] != NULL \
		&& ft_strcmp(i->par->args[0], "..") == 0)
		{
			i->c->parent_dir = get_parent_directory(i->c->pwd);
			return (i->c->parent_dir);
		}
		i->c->curr = i->c->curr->next;
	}
	return (i->par->args[0]);
}

char	*get_parent_directory(char *path)
{
	char	*last_slash;

	last_slash = ft_strrchr(path, '/');
	if (last_slash != NULL)
		*last_slash = '\0';
	return (path);
}
