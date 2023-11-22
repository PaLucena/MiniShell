/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_signal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:11:39 by rdelicad          #+#    #+#             */
/*   Updated: 2023/11/22 14:33:54 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_manager(t_info *i)
{
	(void)i;
	signal(SIGINT, handler_sigusr);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
}

void	handler_sigusr(int signum)
{
	(void)signum;
	{
		if (g_signal_detector == BASE)
		{
			rl_on_new_line();
			rl_redisplay();
			ft_putstr_fd("   \n", 1);
			rl_replace_line("", 0);
			rl_on_new_line();
			rl_redisplay();
		} 
		else if (g_signal_detector == MID_CMD)
		{
			rl_on_new_line();
			ft_putstr_fd("   \n", 1);
		} 
		if (g_signal_detector == HEREDOC)
		{
			ft_putstr_fd("   \n", 1);
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
		}
	} 
	/* if (g_signal_detector == BASE || g_signal_detector == MID_CMD)
	{
		rl_on_new_line();
		rl_redisplay();
		rl_replace_line("", 0);
		write(1, "\033[K\n", 5);
		rl_on_new_line();
		rl_redisplay();
		rl_replace_line("", 0);
	}
	if (g_signal_detector == HEREDOC)
	{
		write(1, "\n", 1);
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
	} */
}

void	control_d(t_info *i)
{
	(void)i;
	rl_on_new_line();
	rl_redisplay();
	ft_putstr_fd("exit\n", 1);
	// ft_free_list(i->c->list_env);
	// free(i->c);
	if (i)
		free_info(i);
	exit (0);
}
