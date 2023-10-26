/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:15:28 by rdelicad          #+#    #+#             */
/*   Updated: 2023/10/26 13:34:48 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/env.h"

void	init_struct(t_cmd *c)
{
	c->argv_env = NULL;
	c->equal_sign = NULL;
	c->key = NULL;
	c->list_env = NULL;
	c->value = NULL;
}

int	len_envp(char **envp)
{
	int	len;

	len = 0;
	while (envp[len] != NULL)
		len++;
	return (len);
}

void	create_list_env(t_cmd *c, char **envp, int len_envp)
{
	t_env	*new;
	int		i;

	new = NULL;
	i = 0;
	while (i < len_envp)
	{
		c->equal_sign = ft_strchr(envp[i], '=');
		if (c->equal_sign != NULL)
		{
			c->key = ft_strldup(envp[i], c->equal_sign - envp[i]);
			c->value = ft_strdup(c->equal_sign + 1);
			new = ft_lstnew_env(c->key, c->value);
			ft_lstadd_back_env(&c->list_env, new);
		}
		i++;
	}
}

int	main(int ac, char **av, char **envp)
{
	t_cmd	c;

	init_struct(&c);
	create_list_env(&c, envp, len_envp(envp));
	if (ac >= 2)
	{
		if (!ft_strcmp(av[1], "env"))
			ft_env(&c);
		else if (!ft_strcmp(av[1], "export"))
		{
			if (ac > 2)
			{
				c.argv_env = av[2];
			}
			ft_export(&c);
		}
		else
			ft_printf("error");
	}
	ft_free_list(&c);
	//atexit(leaks);
	return (0);
}
