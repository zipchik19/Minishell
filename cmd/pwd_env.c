/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 10:53:26 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/23 10:53:27 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	pwd_cmd(t_env **l_env)
{
	t_env	*tmp;

	tmp = get_env(l_env, "PWD");
	if (tmp == NULL)
		print_error("PWD", "No such file or directory", 127);
	else
		printf("%s\n", tmp->value);
}

void	env_cmd(t_env *env)
{
	while (env)
	{
		if (env && env->flag)
		{
			printf("%s", env->key);
			printf("=");
			if (env->value)
				printf("%s\n", env->value);
			else
				printf("\n");
		}
		env = env->next;
	}
}
