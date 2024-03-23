/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 10:51:45 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/23 10:51:47 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_env	*get_env(t_env **l_env, char *new_key)
{
	t_env	*env;

	env = *l_env;
	while (env)
	{
		if (ft_strcmp1(new_key, env->key))
			env = env->next;
		else
			return (env);
	}
	return (0);
}

int	find_key(t_env **l_env, char *new_key)
{
	t_env	*env;

	env = *l_env;
	while (env)
	{
		if (ft_strcmp1(new_key, env->key) != 0 && env)
			env = env->next;
		else
			return (1);
	}
	return (0);
}

void	already_exist(char **splited, t_env *rtv)
{
	if (splited[1])
	{
		rtv->value = splited[1];
		rtv->flag = 1;
		free(splited[0]);
	}
	else
	{
		free(splited[0]);
		rtv->flag = 1;
	}
}

void	key_not_exist(char **splited, t_env *env, int i, int len)
{
	if (splited[1])
	{
		env->flag = 1;
		env->value = splited[1];
	}
	else if (i && i == len - 1)
	{	
			env->flag = 1;
			env->value = 0;
	}
	else
	{
		env->flag = 0;
		env->value = 0;
	}
	env->next = NULL;
}

void	export_cmd(t_env **l_env, char *str, char *cmd)
{
	int		i;
	t_env	*env;
	int		len;
	char	**splited;

	len = ft_strlen(str);
	i = ft_int_strchr(str, '=');
	splited = split_export(str);
	if (exp_pars(splited[0], splited[1], cmd))
	{
		free_envs(splited);
		return ;
	}
	if (!if_key_already_exist(l_env, splited))
	{
		env = malloc(sizeof(t_env));
		env->key = splited[0];
		key_not_exist(splited, env, i, len);
		ft_lstadd_back(l_env, env);
	}
	free(splited);
}
