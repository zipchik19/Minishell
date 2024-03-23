/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 08:54:12 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/23 08:54:21 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	execve_cmd2(t_env **env, char **str)
{
	t_env	*path;
	char	**splited_path;
	char	*new_str;
	char	**mx_env;
	int		i;

	i = 0;
	path = get_env(env, "PATH");
	if (path)
	{
		splited_path = ft_split(path->value, ':');
		new_str = ft_strjoin("/", str[0]);
		create_the_paths(splited_path, new_str);
		free(new_str);
		new_str = 0;
		mx_env = t_env_to_matrix(env);
		new_str = cheack_access(splited_path, str, mx_env);
		ft_execv(new_str, mx_env, str);
		free_envs(mx_env);
		free_envs(splited_path);
	}
	return ;
}

void	signal_execve(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	processing_status(1);
}

void	ft_execve_cmd_part2(char **splited_path,
			char **str, t_env **env, char *new_str)
{
	char	**mx_env;
	int		pid;

	pid = 0;
	mx_env = t_env_to_matrix(env);
	pid = fork();
	if (pid == 0)
	{
		sig_control(0);
		new_str = cheack_access(splited_path, str, mx_env);
		ft_execv(new_str, mx_env, str);
	}
	else
		signal_execve();
	free_envs(mx_env);
	free_envs(splited_path);
}

void	execve_cmd(t_env **env, char **str)
{
	t_env	*path;
	char	**splited_path;
	char	*new_str;

	path = get_env(env, "PATH");
	if (path)
	{
		splited_path = ft_split(path->value, ':');
		new_str = ft_strjoin("/", str[0]);
		create_the_paths(splited_path, new_str);
		free(new_str);
		ft_execve_cmd_part2(splited_path, str, env, new_str);
	}
	else
		print_error(str[0], "No such file or directory", 127);
	return ;
}
