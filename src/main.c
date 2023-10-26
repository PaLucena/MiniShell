/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:15:28 by rdelicad          #+#    #+#             */
/*   Updated: 2023/10/26 09:11:11 by rdelicad         ###   ########.fr       */
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

t_env	*create_list_env(t_cmd *c, char **envp, int len_envp)
{
	t_env	*env;
	int		i;
	char	*key;
	char	*value;

	env = NULL;
	i = 0;
	while (i < len_envp)
	{
		c->equal_sign = ft_strchr(envp[i], '=');
		if (c->equal_sign != NULL)
		{
			c->key = ft_strldup(envp[i], c->equal_sign - envp[i]);
			c->value = ft_strdup(c->equal_sign + 1);
			key = c->key;
			value = c->value;
			ft_lstadd_back_env(&env, ft_lstnew_env(key, value));
			free(c->key);
			free(c->value);
		}
		i++;
	}
	return (env);
}

int	main(int ac, char **av, char **envp)
{
	t_cmd	c;

	init_struct(&c);
	c.list_env = create_list_env(&c, envp, len_envp(envp));
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
