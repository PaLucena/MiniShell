/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:07:37 by palucena          #+#    #+#             */
/*   Updated: 2023/11/02 18:34:56 by palucena         ###   ########.fr       */
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

void	manage_input(char *input, char **argv)
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
			manage_input(input, argv);
		add_history(input);
		free(input);
	}
	return (0);
}
