/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_env_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:01:55 by palucena          #+#    #+#             */
/*   Updated: 2023/11/21 15:57:38 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*init_struct(void)
{
	t_cmd	*c;

	c = malloc(sizeof(t_cmd));
	c->argv_env = NULL;
	c->argv_unset = NULL;
	c->equal_sign = NULL;
	c->key = NULL;
	c->list_env = NULL;
	c->value = NULL;
	c->pwd = NULL;
	c->input = NULL;
	c->curr = NULL;
	c->parent_dir = NULL;
	return (c);
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
	char	*key;
	char	*value;

	new = NULL;
	i = 0;
	while (i < len_envp)
	{
		c->equal_sign = ft_strchr(envp[i], '=');
		if (c->equal_sign != NULL)
		{
			key = ft_strldup(envp[i], c->equal_sign - envp[i]);
			value = ft_strdup(c->equal_sign + 1);
			new = ft_lstnew_env(key, value);
			ft_lstadd_back_env(&c->list_env, new);
			if (ft_strchr(envp[i], '='))
				new->equal = 1;
			free(key);
			free(value);
		}
		i++;
	}
	changer_env_cmd(c);
}

void	changer_env_cmd(t_cmd *c)
{
	t_env	*curr;

	curr = c->list_env;
	while (curr)
	{
		if (curr->key[0] == '_' && curr->key[1] == '\0')
		{
			free(curr->value);
			curr->value = ft_strdup("/usr/bin/env");
			break ;
		}
		curr = curr->next;
	}
}

void	ft_shell_lvl(t_env *list_env)
{
	t_env	*curr;
	char	*aux;

	curr = list_env;
	while (curr && ft_strcmp(curr->key, "SHLVL"))
		curr = curr->next;
	if (!curr)
		return ;
	aux = curr->value;
	curr->value = ft_itoa(ft_atoi(curr->value) + 1);
	free(aux);
	// Cambiar el SHLVL a atoi + 1
}
