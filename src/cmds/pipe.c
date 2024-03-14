/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:40:10 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/14 19:40:11 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	child_pr(int (*fd)[2], int i, int count)
{
	if (i == 0)
	{
		dup2(fd[0][1], 1);
	}
	else if (i == count - 1)
	{
		dup2(fd[i - 1][0], 0);
	}
	else
	{
		dup2(fd[i - 1][0], 0);
		dup2(fd[i][1], 1);
	}
	fd_close(fd, count);
}

void	pipe_call(int (*fd)[2], int count)
{
	int	i;

	i = 0;
	while (i < count - 1)
	{
		pipe(fd[i]);
		i++;
	}
}

void	child_error(int i, pid_t *child )
{
	while (i >= 0)
	{
		kill(child[i], SIGKILL);
		waitpid(child[i], NULL, WUNTRACED);
		i--;
	}
	ft_putstr_fd("fork error\n", 2);
}

void	run_p(pid_t *child, t_tokens **token, t_env **env, int (*fd)[2])
{
	int			i;

	i = 0;
	while ((*token))
	{
		child[i] = fork();
		if (child[i] == -1)
		{
			child_error(i, child);
			break ;
		}
		else if (child[i] == 0)
		{
			sig_control(0);
			running_p((token), env, fd, i);
			exit(1);
		}
		i++;
		(*token) = (*token)->next;
	}
}

void	running_pipe(t_tokens **token, t_env **env)
{
	int			(*fd)[2];
	pid_t		*child;
	t_tokens	*tok;

	tok = *token;
	fd = ft_calloc(sizeof(int *), (*token)->table_count - 1);
	child = malloc(sizeof(int) * (*token)->table_count);
	pipe_call(fd, (*token)->table_count);
	func_red(token);
	run_p(child, token, env, fd);
	(*token) = tok;
	closee(fd, (*token)->table_count);
	processing_status_pipe(child, (*token)->table_count);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	free(child);
	free(fd);
}
