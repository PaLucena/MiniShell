/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_cd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:40:50 by rdelicad          #+#    #+#             */
/*   Updated: 2023/11/18 14:02:19 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd(t_info *i)
{
	i->c->pwd = get_pwd(i->c);
	i->c->input = get_directory_path(i);
	if (ft_strcmp(i->c->input, "") == 0 || ft_strcmp(i->c->input, "-") == 0)
		check_oldpwd(i);
	else if (chdir(i->c->input) != 0 \
	&& i->c->input != NULL && ft_strcmp(i->c->input, "~") != 0 \
	&& ft_strcmp(i->c->input, "-") != 0)
	{
		printf("%s\n", i->c->input);
		write (2, "cd: ", 4);
		write (2, i->par->args[0], ft_strlen(i->par->args[0]));
		write (2, ": No such file or directory", 27);
		write (2, "\n", 1);
		i->status = 1;
	}
	else if (i->c->input == NULL || ft_strcmp(i->c->input, "~") == 0)
	{
		env_error("HOME");
		i->status = 0;
	}
	else
	{
		changer_oldpwd_env(i->c, i->c->pwd);
		changer_pwd_env(i->c);
	}
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
		perror("error");
	}
	return (c->pwd);
}

int	clear_env(t_info *i)
{
	t_env	*curr;

	curr = i->c->list_env;
	while (i->c->curr)
	{
		if (!(ft_strcmp(curr->key, "HOME") == 0))
		{
			return (0);
		}
		curr = curr->next;
	}
	return (1);
}
