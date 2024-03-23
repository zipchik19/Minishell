/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 10:55:05 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/23 10:55:07 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	init_term(void)
{
	struct termios	term;

	tcgetattr(0, &term);
	term.c_lflag &= ~ECHO;
	term.c_lflag &= ~ECHOCTL;
	term.c_lflag |= ECHO;
	tcsetattr(0, 0, &term);
}

void	reset_term(void)
{
	struct termios	term;

	tcgetattr(0, &term);
	term.c_lflag |= ECHOCTL;
	tcsetattr(0, 0, &term);
}

void	sig_control(int a)
{
	if (a == 0)
	{
		reset_term();
		g_exit_code = 290;
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
	}
	else if (a == 1)
	{
		init_term();
		signal(SIGINT, sigint_handler);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (a == 2)
	{
		signal(SIGINT, sig_handler_hdoc);
		signal(SIGQUIT, SIG_IGN);
	}
}

void	sigint_handler(int sig)
{
	if (sig == SIGINT)
	{
		g_exit_code = 1;
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
		rl_replace_line("", 0);
		rl_on_new_line();
	}
}

void	sig_handler_hdoc(int sig)
{
	(void)sig;
	g_exit_code = -14;
	rl_replace_line("", 0);
	rl_on_new_line();
}
