/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:39:37 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/16 13:41:29 by tumolabs         ###   ########.fr       */
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

void	export_print(char *str, int z)
{
	(void)str;
	g_exit_code = z;
	printf("bash: export: `%s': not a valid identifier\n", str);
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
	if (export_pars(splited[0]))
	{
		matrix_free(splited);
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

int	export_pars(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if ((str[i] && (ft_strcharcmp(METAE, str[i])))
			|| (str[i] == '+' && i != len - 1)
			|| (str[i] >= '0' && str[i] <= '9'))
		{
			export_print(str, 1);
			return (1);
		}
		i++;
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
