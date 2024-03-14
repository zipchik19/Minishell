/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:38:54 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/14 19:38:57 by nbadalia         ###   ########.fr       */
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
		matrix_free(mx_env);
		matrix_free(splited_path);
	}
	return ;
}
