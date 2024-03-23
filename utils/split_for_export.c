/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_for_export.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:30:38 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/23 11:30:40 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**split_export(char *str)
{
	int		i;
	int		len;
	char	**ptr;

	i = 0;
	ptr = 0;
	len = ft_strlen(str);
	i = ft_int_strchr(str, '=');
	if (i && i != len - 1)
	{
		ptr = (char **)malloc (sizeof(char *) * (3));
		ptr[0] = ft_substr(str, 0, i);
		ptr[1] = ft_substr(str, i + 1, len - 1);
		ptr[2] = 0;
	}
	else
	{
		if (i && i == len - 1)
			len = len - 1;
			ptr = (char **)malloc (sizeof(char *) * (2));
			ptr[0] = ft_substr(str, 0, len);
			ptr[1] = 0;
	}
	return (ptr);
}
