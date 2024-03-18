/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:38:54 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/16 13:33:52 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*cheack_access(char **path, char **str, char **mx_env)
{
	int	i;

	(void)mx_env;
	i = 0;
	while (path[i])
	{
		if (access(path[i], F_OK) == 0)
		{
			return (path[i]);
		}
		i++;
	}
	return (str[0]);
}

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
		matrix_free(mx_env);
		matrix_free(splited_path);
	}
	return ;
}

void	create_the_paths(char **splited_path, char *new_str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (splited_path[i])
	{
		tmp = splited_path[i];
		splited_path[i] = ft_strjoin(tmp, new_str);
		free(tmp);
		tmp = NULL;
		i++;
	}
}

char	**t_env_to_matrix(t_env **env)
{
	t_env	*l_env;
	char	*tmp;
	char	**new_env;
	int		i;

	i = 0;
	l_env = *env;
	new_env = malloc(sizeof(char *) * (env_len(env) + 1));
	while (l_env && l_env->key && l_env->value)
	{
		tmp = ft_strjoin(l_env->key, "=");
		new_env[i] = ft_strjoin(tmp, l_env->value);
		l_env = l_env->next;
		i++;
		free(tmp);
	}
	new_env[i] = 0;
	return (new_env);
}

void	ft_execv(char *new_str, char **mx_env, char **str)
{
	int	i;

	(void)new_str;
	i = 0;
	if (str[0][0] == '/' || str[0][0] == '.')
		i = execve(str[0], str, mx_env);
	else
		i = execve(new_str, str, mx_env);
	if (i == -1)
	{
		error_msg(str[0], "command not found", 127);
		exit(127);
	}
}
