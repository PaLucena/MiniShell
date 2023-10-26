/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:07:37 by palucena          #+#    #+#             */
/*   Updated: 2023/10/26 17:01:02 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	translate_input(char *input)
{
	t_lx	*lex;
	t_ps	*par;

	lex = l_fill_lx(input);
	par = p_fill_ps(lex);
	while (lex)
	{
		printf("%s %i\n", lex->content, lex->token);
		lex = lex->next;
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	char	*name;
	char	*prompt;

	(void)argc;
	(void)argv;
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
			translate_input(input);
		add_history(input);
		free(input);
	}
	return (0);
}
