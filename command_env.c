/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:15:28 by rdelicad          #+#    #+#             */
/*   Updated: 2023/10/23 20:54:43 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	len_envp(char **envp)
{
	int	len;

	len = 0;
	while (envp[len] != NULL)
		len++;
	return (len);
}

t_env	*create_list_env(char **envp, int len_envp)
{
	t_env	*env;
	int		i;
	char	*equal_sign;
	char	*key;
	char	*value;

	env = NULL;
	i = 0;
	while (i < len_envp)
	{
		equal_sign = strchr(envp[i], '=');
		if (equal_sign != NULL)
		{
			//*equal_sign = '\0';
			key = ft_strldup(envp[i], equal_sign - envp[i]);
			value = strdup(equal_sign + 1);
			ft_lstadd_back(&env, ft_lstnew(key, value));
			free(key);
			free(value);
		}
		i++;
	}
	return (env);
}

void	ft_envp(t_cmd *c)
{
	while (c->list_env != NULL)
	{
		printf("%s=%s\n", c->list_env->key, c->list_env->value);
		c->list_env = c->list_env->next;
	}
}

int	main(int ac, char **av, char **envp)
{
	t_cmd	c;

	c.list_env = create_list_env(envp, len_envp(envp));
	if (ac >= 2)
	{
		if (!strcmp(av[1], "env"))
			ft_envp(&c);
		else if (!strcmp(av[1], "export"))
		{
			if (ac > 2)
			{
				c.environment = av[2];
			}
			ft_export(&c);
		}
		else
			printf("error");
	}
	ft_free_list(&c);
	atexit(leaks);
	return (0);
}
