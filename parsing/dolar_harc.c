/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dolar_harc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 10:58:03 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/23 10:58:05 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	dolar_harc(char **str)
{
	int		i;
	char	*nb;

	i = 0;
	nb = ft_itoa(g_exit_code);
	while ((*str)[i] && (*str)[i + 1])
	{
		if ((*str)[i] == '$' && (*str)[i + 1] == '?')
		{
			*str = dolars_join(*str, nb, i + 1, 2);
			i++;
		}
		else
			i++;
	}
	free (nb);
}
