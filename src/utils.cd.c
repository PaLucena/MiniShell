/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:35:34 by rdelicad          #+#    #+#             */
/*   Updated: 2023/11/06 20:12:54 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/env.h"

char	*get_directory_path(t_cmd *c)
{
	t_env	*curr;
	char	*currDir;
	char	*parentDir;

	curr = c->list_env;
	while (curr)
	{
		if ((ft_strcmp(curr->key, "HOME") == 0) && c->input == NULL)
			return (curr->value);
		else if ((ft_strcmp(curr->key, "HOME") == 0) && (ft_strcmp(c->input,
					"~") == 0))
			return (curr->value);
		else if ((ft_strcmp(curr->key, "OLDPWD") == 0) && (ft_strcmp(c->input,
					"-") == 0))
			return (curr->value);
		else if (ft_strcmp(c->input, "..") == 0)
		{
			currDir = getcwd(NULL, 0);
			parentDir = get_parent_directory(currDir);
			free(currDir);
			return (parentDir);
		}
		else if (ft_strcmp(c->input, "/") == 0)
			return ("/");
		curr = curr->next;
	}
	return (NULL);
}

char	*get_parent_directory(const char *path)
{
	char	*parent_dir;
	char	*last_slash;

	parent_dir = ft_strdup(path);
	last_slash = ft_strrchr(parent_dir, '/');
	if (last_slash != NULL)
		*last_slash = '\0';
	return (parent_dir);
}
