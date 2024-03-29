/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:03:32 by abastida          #+#    #+#             */
/*   Updated: 2024/02/15 17:38:34 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	norm_handler(int sig)
{
	if (sig == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
		g_err = 1;
	}
	return ;
}

void	interact_handler(int sig)
{
	if (sig == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		g_err = 130;
	}
	else if (sig == SIGQUIT)
	{
		ft_putstr_fd("Quit: 3\n", 1);
		g_err = 131;
	}
	return ;
}

void	heredoc_handler(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		g_err = 130;
		exit(130);
	}
	return ;
}

void	ign_signal(int signal)
{
	struct sigaction	sa;

	sa.sa_handler = SIG_IGN;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	if (sigaction(signal, &sa, NULL) < 0)
		exit(1);
}

void	set_signals(int mode)
{
	struct sigaction	sa;

	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	if (mode == 0)
		sa.sa_handler = &norm_handler;
	else if (mode == 1)
		sa.sa_handler = &interact_handler;
	else if (mode == 2)
		sa.sa_handler = &heredoc_handler;
	else if (mode == 3)
		sa.sa_handler = &ign_signal;
	sigaction(SIGINT, &sa, NULL);
	if (!mode)
	{
		sa.sa_handler = SIG_IGN;
		sa.sa_flags = SA_RESTART;
		sigemptyset(&sa.sa_mask);
		sigaction(SIGQUIT, &sa, NULL);
	}
	sigaction(SIGQUIT, &sa, NULL);
}
