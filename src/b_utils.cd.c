/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils.cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:35:34 by rdelicad          #+#    #+#             */
/*   Updated: 2023/11/18 12:22:12 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_directory_path(t_info *i)
{
	i->c->curr = i->c->list_env;
	while (i->c->curr)
	{
		if (i->par->args[0] != NULL && ft_strcmp(i->par->args[0], "/") == 0)
			return ("/");
		else if (i->par->args[0] != NULL && ft_strcmp(i->par->args[0], "..") \
		== 0)
		{
			i->c->parent_dir = get_parent_directory(i->c->pwd);
			return (i->c->parent_dir);
		}
		else if ((ft_strcmp(i->c->curr->key, "HOME") == 0) && i->par->args[0] \
		== 0)
			return(i->c->curr->value);
		else if (i->par->args[0] != NULL \
		&& (ft_strcmp(i->c->curr->key, "HOME") == 0) \
		&& (ft_strcmp(i->par->args[0], "~") == 0))
			return (i->c->curr->value);
		else if (i->par->args[0] != NULL \
		&& (ft_strcmp(i->c->curr->key, "OLDPWD") == 0) \
		&& (ft_strcmp(i->par->args[0], "-") == 0))
			return (i->c->curr->value);
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

void	env_error(char *env)
{
	write (1, "cd: ", 4);
	write (1, env, ft_strlen(env));
	write (1, " not set\n", 9);
}

int	no_clear_home(t_info *i, char *key)
{
	if (ft_strcmp(key, "HOME") == 0)
	{
		if (clear_env(i))
			return (0);
		else
			return (1);
	}
	else
		return (0);
}

void	check_oldpwd(t_info *i)
{
	t_env	*curr;

	curr = i->c->list_env;
	while (curr)
	{
		if (ft_strcmp(curr->key, "OLDPWD") == 0)
		{
			if (ft_strcmp(curr->value, "") == 0)
			{
				env_error("OLDPWD");
				i->status = 1;
			}
		}
		curr = curr->next;
	}
}
