/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:07:37 by palucena          #+#    #+#             */
/*   Updated: 2023/11/27 16:28:50 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ps	*manage_input(char *input, t_info *info)
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
	free_lexer(lex);
	return (par);
}

void	init_info(t_info *info, char **envp)
{
	t_env	*curr;

	info->par = NULL;
	info->c = init_struct();
	create_list_env(info->c, envp, len_envp(envp));
	curr = info->c->list_env;
	while (curr)
	{
		if (ft_strcmp(curr->key, "USER") == 0)
		{
			if (ft_strcmp(curr->value, "palucena") == 0)
				info->c->home = "/Users/palucena";
			else
				info->c->home = "/Users/rdelicad";
		}
		curr = curr->next;
	}
	ft_shell_lvl(info->c->list_env);
	clear_value_oldpwd(info->c);
	info->status = 0;
}

static void	ft_minishell(t_info *info)
{
	char	*input;

	while (1)
	{
		input = readline("\033[36;1mminishell$ \033[0m");
		if (g_signal_detector == SIG_C_BASE)
			info->status = 1;
		if (!input)
			control_d(info);
		else
			add_history(input);
		if (ft_strcmp(input, "\0") != 0)
		{
			info->par = manage_input(input, info);
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

	(void)argv;
	if (argc > 1)
		return (127);
	g_signal_detector = BASE;
	info = malloc(sizeof(t_info));
	init_info(info, envp);
	signal_manager(info);
	ft_putstr_fd("\n\nWelcome to MiniShell ", 1);
	ft_putstr_fd("(by \033[34;1m@rdelicad\033[0m &", 1);
	ft_putstr_fd(" \033[34;1m@palucena\033[0m)\n", 1);
	ft_minishell(info);
	free_info(info);
	return (0);
}
