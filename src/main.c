/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:07:37 by palucena          #+#    #+#             */
/*   Updated: 2023/11/24 14:16:44 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_select(t_lx *lex, t_ps *par, char **argv)
{
	int	i;
	int	j;

	if (argv[1] && (ft_strcmp(argv[1], "-l") == 0 || ft_strcmp(argv[1], "-lp") == 0))
	{
		i = 0;
		printf("\033[33;1m	----lexer----\033[0m\n\n");
		while (lex)
		{
			printf("%i. %s, token: %i\n", ++i, lex->content, lex->token);
			lex = lex->next;
		}
		printf("\n\033[33;1m	 ----end----\033[0m\n");
	}
	if (argv[1] && (ft_strcmp(argv[1], "-p")  == 0 || ft_strcmp(argv[1], "-lp")  == 0))
	{
		i = 0;
		printf("\033[33;1m	----parser----\033[0m\n\n");
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

t_ps	*manage_input(char *input, char **argv, t_info *info)
{
	t_lx	*lex;
	t_ps	*par;

	lex = NULL;
	par = NULL;
	if (!l_check_empty(input))
		lex = l_fill_lx(input, info);
	if (!lex)
		return (NULL);
	par = p_fill_ps(lex, NULL);
	info->n_cmds = ft_count_nodes(par);
	print_select(lex, par, argv);
	free_lexer(lex);
	return (par);
}

void	init_info(t_info *info, char **envp)
{
	info->par = NULL;
	info->c = init_struct();
	create_list_env(info->c, envp, len_envp(envp));
	ft_shell_lvl(info->c->list_env);
	clear_value_oldpwd(info->c);
	info->status = 0;
}

static void	ft_minishell(t_info *info, char **argv)
{
	char	*input;

	ft_putstr_fd("\n\nWelcome to MiniShell ", 1);
	ft_putstr_fd("(by \033[34;1m@rdelicad\033[0m &", 1);
	ft_putstr_fd(" \033[34;1m@palucena\033[0m)\n", 1);
	while (1)
	{
		input = readline("\033[36;1mminishell$ \033[0m");
		if (!input)
			control_d(info);
		shell_level_detected(info, input);
		add_history(input);
		if (ft_strcmp(input, "\0") != 0)
		{
			info->par = manage_input(input, argv, info);
			if (info->par && g_signal_detector != CANCEL_EXEC)
			{
				ft_execute(info);
				free_parser(info->par);
			}
		}
		free(input);
		g_signal_detector = BASE;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_info	*info;

	atexit(leaks);
	(void)argc;
	g_signal_detector = BASE;
	info = malloc(sizeof(t_info));
	init_info(info, envp);
	signal_manager(info);
	ft_minishell(info, argv);
	free_info(info);
	return (0);
}
