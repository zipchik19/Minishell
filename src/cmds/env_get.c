/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:38:40 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/14 19:38:43 by nbadalia         ###   ########.fr       */
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
