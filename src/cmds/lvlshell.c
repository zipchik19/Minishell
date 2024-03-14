/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvlshell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:40:03 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/14 19:40:05 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	lvlshell(t_env **env)
{
	t_env	*res;
	int		tmp;

	res = get_env(env, "SHLVL");
	tmp = ft_atoi(res->value);
	free(res->value);
	res->value = ft_itoa(tmp + 1);
}
