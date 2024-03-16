/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:39:37 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/14 19:39:39 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	only_export(t_env **node)
{
	t_env	*curr;

	curr = (*node);
	while (curr)
	{
		printf("declare -x %s", curr->key);
		if (curr->value)
			printf("=\"%s\"\n", curr->value);
		else
			printf("\n");
		curr = curr->next;
	}
}

void	export_cmd(t_env **l_env, char *str)
{
	int		i;
	t_env	*env;
	int		len;
	char	**splited;

	len = ft_strlen(str);
	i = ft_int_strchr(str, '=');
	splited = split_export(str);
	// if (export_pars(splited[0]))
	// {
	// 	matrix_free(splited);
	// 	return ;
	// }
	if (!if_key_already_exist(l_env, splited))
	{
		env = malloc(sizeof(t_env));
		env->key = splited[0];
		key_not_exist(splited, env, i, len);
		ft_lstadd_back(l_env, env);
	}
	free(splited);
}
