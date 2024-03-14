/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:40:25 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/14 19:40:27 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	closee(int (*fd)[2], int count)
{
	int	i;

	i = 0;
	while (i < count - 1)
	{
		close(fd[i][0]);
		close(fd[i][1]);
		i++;
	}
}

void	processing_status_pipe(pid_t *a, int size)
{
	pid_t	pid;
	int		i;
	int		status;

	i = -1;
	status = 0;
	while (++i < size)
	{
		pid = waitpid(-1, &status, 0);
		if (pid == a[size - 1])
		{
			if (!WTERMSIG(status))
				g_exit_code = WEXITSTATUS(status);
			else
			{
				g_exit_code = WTERMSIG(status) + 128;
				if (g_exit_code == 130)
					write(1, "\n", 1);
				else if (g_exit_code == 131)
					ft_putstr_fd1("Quit 3", 1, 1);
			}
		}
	}
}

