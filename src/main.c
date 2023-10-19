/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:07:37 by palucena          #+#    #+#             */
/*   Updated: 2023/10/19 14:05:55 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_lx	*lex;
	char	*input;

	(void)argc;
	(void)argv;
	(void)envp; // este no
	//ft_env(envp);
	lex = malloc(sizeof(t_lx));
	while (1)
	{
		lex = NULL;
		input = readline("\033[36;1mminishell$ \033[0m");
		add_history(input);
		if (ft_lexer(&lex, input) == -1)
			break ;
		if (!input || ft_strncmp(input, "exit\0", 5) == 0)
			break ;
	}
	return (0);
}
