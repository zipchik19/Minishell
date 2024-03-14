/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:47:15 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/14 19:47:16 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	*ft_calloc(size_t count, size_t size)
{	
	size_t	i;
	void	*ptr;

	i = 0;
	if (count >= SIZE_MAX && size >= SIZE_MAX)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	while (i < count * size)
	{
		((char *)ptr)[i] = '\0';
		i++;
	}
	return ((char *)ptr);
}

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

char	*cat_str(char *s)
{
	int		i;
	int		flag;

	flag = 0;
	i = 0;
	if (s[i] == '-')
	{
		flag = 1;
		i++;
	}
	if (s[i] == '+')
	{
		i++;
		flag = 2;
	}
	while (s[i] == '0')
	i++;
	return (ft_cat_str1(s, i, flag));
}
