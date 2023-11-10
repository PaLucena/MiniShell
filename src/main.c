/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:07:37 by palucena          #+#    #+#             */
/*   Updated: 2023/11/10 11:44:13 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_select(t_lx *lex, t_ps *par, char **argv)
{
	if (argv[1] && (ft_strcmp(argv[1], "-l") || ft_strcmp(argv[1], "-lp")))
	{
		int	i = 0;
		printf("\033[33;1m	----lexer----\033[0m\n\n");
		while (lex)
		{
			printf("%i. %s, token: %i\n", ++i, lex->content, lex->token);
			lex = lex->next;
		}
		printf("\n\033[33;1m	 ----end----\033[0m\n");
	}
	if (argv[1] && (ft_strcmp(argv[1], "-p") || ft_strcmp(argv[1], "-lp")))
	{
		int	i = 0;
		printf("\033[33;1m	----parser----\033[0m\n\n");
		int	j;
		while (par)
		{
			j = -1;
			printf("%i. Cmd: %s", ++i, par->cmd);
			while (par->args[0] != NULL && par->args[++j])
				printf(" %s", par->args[j]);
			printf("\n\tfd_in: %i, fd_out: %i\n", par->infile, par->outfile);
			par = par->next;
		}
		printf("\n\033[33;1m	 ----end----\033[0m\n");
	}
}

void	ft_syntax_error(void)
{
	ft_printf("Syntax error\n");
	exit(1);
}

t_ps	*manage_input(char *input, char **argv)
{
	t_lx	*lex;
	t_ps	*par;

	lex = l_fill_lx(input);
	if (!lex)
		return (NULL); // error
	par = p_fill_ps(lex, NULL);
	print_select(lex, par, argv);
	// limpiar lexer
	free_lexer(lex);
	return (par);
}

void	init_info(t_info *info, char **envp)
{
	info->par = NULL;
	info->c = init_struct();
	create_list_env(info->c, envp, len_envp(envp));
	create_path(info->c);
	info->env = info->c->list_env;
	info->status = 0;
	info->exit = false;
}

int	main(int argc, char **argv, char **envp)
{
	t_info	*info;
	char	*input;

	//atexit(leaks);
	(void)argc;
	(void)envp;
	info = malloc(sizeof(t_info));
	init_info(info, envp);
	while (1)
	{
		input = readline("\033[36;1mminishell$ \033[0m");
		add_history(input);
		if (ft_strcmp(input, "\0") != 0)
		{
			info->par = manage_input(input, argv);
			if (!info->par)
				ft_syntax_error();
			ft_execute(info, envp);
			free_parser(info->par);
		}
		free(input);
	}
	free_command(info);
	free(info);
	return (0);
}
