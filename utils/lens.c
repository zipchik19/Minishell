/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lens.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:29:41 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/23 11:29:43 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	env_len(t_env **l_env)
{
	t_env	*env;
	int		count;

	count = 0;
	env = *l_env;
	while (env)
	{
		env = env->next;
		count++;
	}
	return (count);
}

int	matrix_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
