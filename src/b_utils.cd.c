/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils.cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:35:34 by rdelicad          #+#    #+#             */
/*   Updated: 2023/11/08 13:06:06 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_directory_path(t_cmd *c)
{
	t_env	*curr;
	char	*parent_dir;

	curr = c->list_env;
	while (curr)
	{
		if ((ft_strcmp(curr->key, "HOME") == 0) && c->input == NULL)
			return (curr->value);
		else if (c->input != NULL && (ft_strcmp(curr->key, "HOME") == 0)
			&& (ft_strcmp(c->input, "~") == 0))
			return (curr->value);
		else if (c->input != NULL && (ft_strcmp(curr->key, "OLDPWD") == 0)
			&& (ft_strcmp(c->input, "-") == 0))
			return (curr->value);
		else if (c->input != NULL && ft_strcmp(c->input, "/") == 0)
			return ("/");
		else if (c->input != NULL && ft_strcmp(c->input, "..") == 0)
		{
			parent_dir = get_parent_directory(c->pwd);
			return (parent_dir);
		}
		curr = curr->next;
	}
	return (NULL);
}

char	*get_parent_directory(char *path)
{
	char	*last_slash;

	last_slash = ft_strrchr(path, '/');
	if (last_slash != NULL)
		*last_slash = '\0';
	return (path);
}
