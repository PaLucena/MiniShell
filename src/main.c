/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:15:28 by rdelicad          #+#    #+#             */
/*   Updated: 2023/11/03 10:51:28 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/env.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

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

/* int	main(int ac, char **av, char **envp)
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
	ft_free_list(c.list_env);
	//atexit(leaks);
	return (0);
} */
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

    while (1) {
        printf("minishell> ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // Eliminar el salto de línea final
        command[strcspn(command, "\n")] = 0;

        // Dividir el comando en argumentos
        char* token = strtok(command, " ");
        int i = 0;
        while (token != NULL) {
            args[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        args[i] = NULL;

        // Salir de la minishell si se ingresa "exit"
        if (strcmp(args[0], "exit") == 0) {
            break;
        }

        // Verificar los comandos ingresados y llamar a las funciones correspondientes
        if (!strcmp(args[0], "env")) 
            ft_env(&c);
		else if (!strcmp(args[0], "export")) 
		{
            if (i > 1)
                c.argv_env = args[1];
            ft_export(&c);
        }
		else if (!strcmp(args[0], "unset"))
		{
			if (i > 1)
				c.argv_unset = args[1];
			ft_unset(&c.list_env, c.argv_unset);
		}
		else
            ft_printf("Comando inválido.\n");
    }

    ft_free_list(c.list_env);
	ft_matfree(c.path);
    //atexit(leaks);
    return 0;
}