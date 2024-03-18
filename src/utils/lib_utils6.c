/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:47:15 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/16 13:36:08 by tumolabs         ###   ########.fr       */
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

char	*ft_cat_str1(char *s, int i, int flag)
{
	int		j;
	char	*str;

	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) - i + 2));
	if (str == NULL)
		return (NULL);
	if (flag == 1)
		str[j++] = '-';
	else if (flag == 2)
		str[j++] = '+';
	while (s[i] && i < ft_strlen(s))
		str[j++] = s[i++];
	str[j] = '\0';
	if (j == 0)
		return ("0");
	else
		return (str);
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

int	ft_int_strchr(char *str, char c)
{
	unsigned int	i;
	unsigned char	*s;
	int				len;

	s = (unsigned char *) str;
	len = ft_strlen(str);
	i = 0;
	if (c == 0)
		return (len);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (i);
		i++;
	}
	return (0);
}
