/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 10:55:01 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/23 10:55:02 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	shell_level(t_env **env)
{
	t_env	*rtv;
	int		tmp;

	rtv = get_env(env, "SHLVL");
	tmp = ft_atoi(rtv->value);
	free(rtv->value);
	rtv->value = ft_itoa(tmp + 1);
}
