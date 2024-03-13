/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvlshell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:50:24 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/13 19:50:25 by nbadalia         ###   ########.fr       */
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
