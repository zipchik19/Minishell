/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:55:24 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/18 15:55:25 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	if_key_already_exist(t_env **l_env, char **splited)
{
	t_env	*rtv;

	rtv = 0;
	if (if_need_to_add(l_env, splited))
		return (1);
	if (find_key(l_env, splited[0]))
	{
		rtv = get_env(l_env, splited[0]);
		if (rtv->value)
		{
			free(rtv->value);
			free(splited[0]);
			rtv->flag = 1;
			rtv->value = splited[1];
		}
		else
		{
			already_exist(splited, rtv);
		}
		return (1);
	}
	return (0);
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

int	if_need_to_add(t_env **l_env, char **splited)
{
	int		len;
	t_env	*rtv;
	char	*tmp;

	rtv = 0;
	len = ft_strlen(splited[0]);
	if (splited[0][len - 1] == '+')
	{
		tmp = splited[0];
		splited[0] = ft_strtrim(splited[0], "+");
		free(tmp);
		if (find_key(l_env, splited[0]))
		{
			need_to_add(l_env, splited, rtv, tmp);
			return (1);
		}
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

void	need_to_add(t_env **l_env, char **splited, t_env *rtv, char *tmp)
{
	if (!splited[1])
	{
		free(splited[0]);
		return ;
	}
	rtv = get_env(l_env, splited[0]);
	free(splited[0]);
	if (!rtv->value)
		rtv->value = splited[1];
	else
	{
		tmp = rtv->value;
		rtv->value = ft_strjoin(tmp, splited[1]);
		free(splited[1]);
		free(tmp);
	}
}
