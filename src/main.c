/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:07:37 by palucena          #+#    #+#             */
/*   Updated: 2023/10/25 00:31:18 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	t_lx	*lex;

	(void)argc;
	(void)argv;
	(void)envp; // este no
	//ft_env(envp);
	while (1)
	{
		input = readline("\033[36;1mminishell$ \033[0m");
		if (!input || ft_strcmp(input, "exit"))
			break ;
		if (!ft_strcmp(input, "\0"))
			lex = l_fill_lx(input);
		add_history(input);
		free(input);
	}
	return (0);
}
