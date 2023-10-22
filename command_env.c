/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:15:28 by rdelicad          #+#    #+#             */
/*   Updated: 2023/10/22 16:09:05 by rdelicad         ###   ########.fr       */
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

	
	env = NULL;
	i = 0;
	while (i < len_envp)
    {
        equal_sign = strchr(envp[i], '=');
        if (equal_sign != NULL)
        {
            *equal_sign = '\0';
            ft_lstadd_back(&env, ft_lstnew(envp[i], equal_sign + 1));
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
	ft_free_list(c->list_env);
}

int	main(int ac, char **av, char **envp)
{
	t_cmd	c;

	c.list_env = create_list_env(envp, len_envp(envp));
	if (ac == 2)
	{
		if (!strcmp(av[1], "env"))
			ft_envp(&c);
		else if (!strcmp(av[1], "export"))
			ft_export(&c);
		else
			printf("error");
	}
	//ft_free_list(c.list_env);
	return (0);
}