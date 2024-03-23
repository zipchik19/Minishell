/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:29:07 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/23 11:29:08 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_substr(char *s, int start, int len)
{
	char	*str;
	int		i;
	int		k;

	i = 0;
	if (start > ft_strlen(s))
		k = 0;
	else if (ft_strlen(s) - start > len)
		k = len;
	else
		k = ft_strlen(s) - start;
	str = (char *) malloc(sizeof(char) * (k + 1));
	if (str == NULL)
		return (NULL);
	while (s[i] && len > 0 && start < ft_strlen(s))
	{
		str[i++] = s[start++];
		len--;
	}
	str[i] = '\0';
	return (str);
}
