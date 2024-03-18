/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:41:25 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/16 14:32:07 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include <readline/readline.h>

void	sigint_handler(int sig)
{
	if (sig == SIGINT)
	{
		g_exit_code = 1;
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
