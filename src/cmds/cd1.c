/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:38:12 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/14 19:38:16 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	cd_cmd(t_env **l_env, char **str)
{
	update_oldpwd(l_env);
	if ((ft_strcmp("cd", str[0]) && !str[1]) || ft_strcmp("~", str[1]))
		chdir(get_env(l_env, "HOME")->value);
	else
	{
		if (chdir(str[1]) == -1)
			error_msg(str[1], "No such file or directory", 1);
	}
	update_pwd(l_env);
}

void	update_pwd(t_env **l_env)
{
	t_env	*env;
	char	*tmp;
	char	cwd[256];

	env = get_env(l_env, "PWD");
	tmp = env->value;
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		env->value = ft_strduplist(getcwd(cwd, sizeof(cwd)));
	free(tmp);
}

void	update_oldpwd(t_env **l_env)
{
	t_env	*env;

	env = get_env(l_env, "OLDPWD");
	if (env == 0)
	{
		env = malloc(sizeof(t_env));
		env->key = "OLDPWD";
		env->flag = 1;
		env->value = ft_strduplist(get_env(l_env, "PWD")->value);
		ft_lstadd_back(l_env, env);
	}
	else if (env)
	{
		env->flag = 1;
		free(env->value);
		env->value = ft_strduplist(get_env(l_env, "PWD")->value);
	}
}
