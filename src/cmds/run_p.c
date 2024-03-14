/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:41:17 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/14 19:41:19 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	running_p_part1(t_tokens *token, t_env **l_env, t_env *env)
{
	int	j;

	j = 1;
	if (ft_strcmp1(token->cmd[0], "exit") == 0)
		exit_cmd(token->cmd);
	else if (ft_strcmp1(token->cmd[0], "pwd") == 0)
		pwd_cmd(l_env);
	else if (ft_strcmp1(token->cmd[0], "env") == 0)
		env_cmd(env);
	else if (ft_strcmp1(token->cmd[0], "export") == 0 && !token->cmd[1])
		only_export(l_env);
	else if (ft_strcmp1(token->cmd[0], "export") == 0)
	{
		while (token->cmd[j])
			export_cmd(l_env, token->cmd[j++]);
	}
	else if (ft_strcmp1(token->cmd[0], "cd") == 0)
		cd_cmd(l_env, token->cmd);
	else if (ft_strcmp1(token->cmd[0], "echo") == 0)
		echo_cmd(token->cmd);
	else if (ft_strcmp1(token->cmd[0], "unset") == 0)
		unset_cmd(l_env, token->cmd[1]);
	else
		execve_cmd2(l_env, token->cmd);
}

void	running_p(t_tokens **token, t_env **l_env, int (*fd)[2], int i)
{
	t_env		*env;
	t_tokens	*tk;
	int			j;
	t_count		*all_count;

	env = *l_env;
	tk = *token;
	j = 1;
	all_count = NULL;
	all_count = count_redirect((token));
	child_pr(fd, i, (*token)->token_count);
	call_redirections6((token), all_count);
	if ((*token)->cmd && (*token)->cmd[0])
		running_p_part1(tk, l_env, env);
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
