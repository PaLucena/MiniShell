/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:15:28 by rdelicad          #+#    #+#             */
/*   Updated: 2023/10/21 13:08:39 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"


char	**create_copy_array_envp(char **envp, int len)
{
	char	**copy_envp;
	int		i;

	copy_envp = malloc(sizeof(char *) * (len));
	if (!copy_envp)
		return (free(copy_envp), NULL);
	i = 0;
	while (i < len)
	{
		copy_envp[i] = envp[i];
		i++;
	}
	// copy_envp[i] = NULL;
	return (copy_envp);
}

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


void	ft_envp(char **envp)
{
	t_env	*list_env;
	t_env	*aux;

	list_env = create_list_env(envp, len_envp(envp));
	aux = list_env;
	while (aux != NULL)
	{
		printf("%s=%s\n", aux->key, aux->value);
		aux = aux->next;
	}
	// ft_split(envp, '\n');
}

int	main(int ac, char **av, char **envp)
{
	//t_env *list_env;
	(void)ac;
	(void)av;
	ft_envp(envp);
	/* int i = 0;
	while (envp[i] != NULL)
	{
		printf("%s\n", envp[i]);
		i++;
	} */
	return (0);
}