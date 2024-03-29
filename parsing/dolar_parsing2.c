/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dolar_parsing2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 10:58:40 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/23 10:58:41 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	skip_find_sp_idx(char *str, int i)
{
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] && str[i] != ' ')
		i++;
	return (i);
}

char	*dolars_join(char *str, char *world, int x, int z)
{
	int		len_s;
	char	*new_str;
	char	*res;
	char	*tmp;

	len_s = ft_strlen(str);
	new_str = ft_substr(str, 0, x - 1);
	res = new_str;
	if (world)
	{
		new_str = ft_strjoin(new_str, world);
		free(res);
		res = new_str;
	}
	tmp = ft_substr(str, x + z - 1, len_s);
	res = new_str;
	new_str = ft_strjoin(new_str, tmp);
	free(tmp);
	free(res);
	free(str);
	return (new_str);
}
