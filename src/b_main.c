/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:15:28 by rdelicad          #+#    #+#             */
/*   Updated: 2023/11/08 09:09:55 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/env.h"

void	init_struct(t_cmd *c)
{
	c->argv_env = NULL;
	c->argv_exit = NULL;
	c->argv_unset = NULL;
	c->equal_sign = NULL;
	c->key = NULL;
	c->list_env = NULL;
	c->value = NULL;
	c->pwd = NULL;
	c->input = NULL;
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
}

void	create_path(t_cmd *c)
{
	t_env	*curr;

	curr = c->list_env;
	while (curr)
	{
		if (ft_strcmp(curr->key, "PATH") == 0)
		{
			c->path = ft_split(curr->value, ':');
		}
		curr = curr->next;
	}
}
#define MAX_COMMAND_LENGTH 100

int main(int ac, char** av, char** envp) 
{
    t_cmd c;
	(void)ac;
	(void)av;
    init_struct(&c);
    create_list_env(&c, envp, len_envp(envp));
	create_path(&c);

    char command[MAX_COMMAND_LENGTH];
    char* args[MAX_COMMAND_LENGTH];

    while (1) 
	{
        printf("minishell> ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // Eliminar el salto de línea final
        command[
			strcspn(command, "\n")] = 0;

        // Dividir el comando en argumentos
        char* token = strtok(command, " ");
        int i = 0;
            args[i] = token;
        while (token != NULL) 
		{
			args[i] = token;
            i++;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        // Salir de la minishell si se ingresa "exit"
        if (ft_strcmp(args[0], "exit") == 0)
		{
			if (i > 1)
				c.argv_exit = args[1];
			ft_exit(&c);
			break;
		}

        // Verificar los comandos ingresados y llamar a las funciones correspondientes
        ft_builtins(&c, args, i);
    }

    ft_free_list(c.list_env);
	ft_matfree(c.path);
    //atexit(leaks);
    return 0;
}