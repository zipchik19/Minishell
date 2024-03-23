/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 10:57:00 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/23 10:57:01 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ctrl_d_check(char *s)
{
	if (!s)
	{
		write(1, "exit\n", 5);
		exit(g_exit_code);
	}
}

int	sp_trim(char *str)
{
	char	*res;

	res = ft_strtrim(str, " ");
	if (res == NULL)
		return (0);
	else
	{
		free(res);
		return (1);
	}
}
