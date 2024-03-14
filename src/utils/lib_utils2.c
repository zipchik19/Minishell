/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:46:32 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/14 19:46:34 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	ft_strcmp2(char *str, char *cmd, int len)
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
	i = 0;
	j = 0;
	while (cmd && str && cmd[j] && str[i])
	{
		while (str[i++] == cmd[j++])
		{
			if (j == len - 1)
				return (1);
		}
		if (j == 0)
				flag = 1;
			j = 0;
		if (flag)
		{
			i++;
			flag = 0;
		}
	}
	return (0);
}

int	ft_strcmp(char *str, char *cmd)
{
	int	len;
	int	result;

	len = ft_strlen(cmd);
	if (len != ft_strlen(str))
		return (0);
	result = ft_strcmp2(str, cmd, len);
	return (result);
}

int	ft_strcmp1(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1 && s2 && s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	sign;

	sign = 1;
	i = 0;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (sign * num);
}
