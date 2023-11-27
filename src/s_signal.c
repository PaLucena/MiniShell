/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_signal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:11:39 by rdelicad          #+#    #+#             */
/*   Updated: 2023/11/27 16:32:52 by palucena         ###   ########.fr       */
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
	if (g_signal_detector == BASE || g_signal_detector == SIG_C_BASE)
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
		g_signal_detector = SIG_C_CMD;
		ft_putstr_fd("\n", 1);
		rl_on_new_line();
	}
	else if (g_signal_detector == HEREDOC)
	{
		ft_putstr_fd(">    \n", 1);
		exit(0);
	}
	if (g_signal_detector == HEREDOC_DAD)
		g_signal_detector = CANCEL_EXEC;
	else if (g_signal_detector == BASE || g_signal_detector == HEREDOC)
		g_signal_detector = SIG_C_BASE;
}

void	control_d(t_info *i)
{
	(void)i;
	rl_on_new_line();
	rl_redisplay();
	ft_putstr_fd("exit\n", 1);
	exit (0);
}
