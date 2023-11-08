/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:40:50 by rdelicad          #+#    #+#             */
/*   Updated: 2023/11/07 17:40:07 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/env.h"

void	ft_cd(t_cmd	*c)
{
	c->pwd = get_pwd(c);
	c->input = get_directory_path(c);
	if (chdir(c->input) != 0)
		perror("Error al cambiar de directorio");
	changer_oldpwd_env(c, c->pwd);
	changer_pwd_env(c);
}

void	changer_oldpwd_env(t_cmd *c, char *oldpwd)
{
	t_env	*curr;

	curr = c->list_env;
	while (curr)
	{
		if (ft_strcmp(curr->key, "OLDPWD") == 0)
		{
			free(curr->value);
			curr->value = ft_strdup(oldpwd);
		}
		curr = curr->next;
	}
	free(oldpwd);
}

void	changer_pwd_env(t_cmd *c)
{
	t_env	*curr;

	curr = c->list_env;
	while (curr)
	{
		if (ft_strcmp(curr->key, "PWD") == 0)
		{
			c->pwd = get_pwd(c);
			free(curr->value);
			curr->value = ft_strdup(c->pwd);
		}
		curr = curr->next;
	}
	free(c->pwd);
}

char	*get_pwd(t_cmd *c)
{
	c->pwd = getcwd(NULL, 0);
	if (c->pwd == NULL)
	{
		perror("Error al obtener el directorion en CD");
	}
	return (c->pwd);
}
