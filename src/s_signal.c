/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_signal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:11:39 by rdelicad          #+#    #+#             */
/*   Updated: 2023/11/14 19:12:05 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_manager(t_info *i)
{
	(void)i;
	signal(SIGINT, handler_sigusr);
	signal(SIGQUIT, SIG_IGN);
}

void	handler_sigusr(int signum)
{
	if (signum == SIGINT)
	{
		rl_on_new_line();
		rl_redisplay();
		write (1, "   \n", 4);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	control_d(t_info *i)
{
	rl_on_new_line();
	rl_redisplay();
	ft_putstr_fd("exit\n", 1);
	ft_free_list(i->c->list_env);
	ft_matfree(i->c->path);
	free(i->c);
	free(i);
	exit (0);
}
