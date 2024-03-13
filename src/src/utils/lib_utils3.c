/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:53:27 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/13 19:53:28 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_strdup(char *s1)
{
	char	*s_copy;
	int		i;

	s_copy = malloc(ft_strlen(s1) + 1);
	if (!s_copy)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s_copy[i] = s1[i];
		i++;
	}
	s_copy[i] = '\0';
	return (s_copy);
}

int	str_len(int n)
{
	size_t	digit;

	digit = 0;
	if (n < 0)
	{
		n *= -1;
		digit++;
	}
	while (n)
	{
		digit++;
		n = n / 10;
	}
	return (digit);
}

char	*ft_itoa(int n)
{	
	char		*s;
	size_t		len;
	long int	numb;

	numb = n;
	if (numb == 0)
		return (ft_strdup("0"));
	len = str_len(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	if (numb < 0)
	{
		s[0] = '-';
		numb *= -1;
	}
	s[len] = '\0';
	while (numb > 0)
	{
		s[(len--) - 1] = (numb % 10) + '0';
		numb = numb / 10;
	}
	return (s);
}
