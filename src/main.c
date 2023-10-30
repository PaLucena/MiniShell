/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:07:37 by palucena          #+#    #+#             */
/*   Updated: 2023/10/30 23:57:51 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_select(t_lx *lex, t_ps *par, char **argv)
{
	if (argv[1] && (ft_strcmp(argv[1], "-l") || ft_strcmp(argv[1], "-lp")))
	{
		int	i = 0;
		ft_printf("\033[33;1m	----lexer----\033[0m\n\n");
		while (lex)
		{
			ft_printf("%i. %s, token: %i\n", ++i, lex->content, lex->token);
			lex = lex->next;
		}
		ft_printf("\n\033[33;1m	 ----end----\033[0m\n");
	}
	if (argv[1] && (ft_strcmp(argv[1], "-p") || ft_strcmp(argv[1], "-lp")))
	{
		int	i = 0;
		ft_printf("\033[33;1m	----parser----\033[0m\n\n");
		int	j;
		while (par)
		{
			j = -1;
			ft_printf("%i. Cmd: %s", ++i, par->cmd);
			while (par->args[0] != NULL && par->args[++j])
				ft_printf(" %s", par->args[j]);
			ft_printf("\n");
			par = par->next;
		}
		ft_printf("\n\033[33;1m	 ----end----\033[0m\n");
	}
}

void	translate_input(char *input, char **argv)
{
	t_lx	*lex;
	t_ps	*par;

	lex = l_fill_lx(input);
	if (!lex)
		return ; // error
	par = p_fill_ps(lex, NULL);
	print_select(lex, par, argv);
}

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	char	*name;
	char	*prompt;

	(void)argc;
	(void)envp; // este no
	//ft_env(envp);
	name = "minishell";
	prompt = ft_strjoin(ft_strjoin("\033[36;1m", name), "$ \033[0m");
	while (1)
	{
		input = readline(prompt);
		if (!input || ft_strcmp(input, "exit"))
			break ;
		if (!ft_strcmp(input, "\0"))
			translate_input(input, argv);
		add_history(input);
		free(input);
	}
	return (0);
}
