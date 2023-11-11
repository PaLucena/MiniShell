/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_signal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:11:39 by rdelicad          #+#    #+#             */
/*   Updated: 2023/11/11 18:37:49 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_manager(t_info *i)
{
	(void)i;
	struct sigaction	action;

	action.sa_sigaction = handler_sigusr;
	action.sa_flags = 0;
	sigaction(SIGINT, &action, NULL); //Ctrl + C
	sigaction(SIGQUIT, &action, NULL);//Ctrl + \/
	sigaction(SIGPIPE, &action, NULL);//Ctrl + D
}

void	handler_sigusr(int signum, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;

	if (signum == SIGPIPE)
	{
		//printf("\n");
		exit (0);
	}
}