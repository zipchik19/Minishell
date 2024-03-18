/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:43:18 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/14 19:43:20 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	front(char *str, int *i)
{
	int	j;

	while (str[*i] && str[*i] == ' ')
		(*i)++;
	j = *i;
	while (str[*i] && !ft_strchr(METACHARS, str[*i]))
		(*i)++;
	if (*i - j <= 0)
		return (1);
	return (0);
}

int	back(char *str, int i)
{
	int	j;

	if (i == 0)
		return (1);
	while (str[i] && str[i] == ' ')
		i--;
	j = i;
	while (!ft_strchr(METACHARS, str[i]) && str[j])
		i--;
	if (j - i <= 0)
		return (1);
	return (0);
}

int	part2(int i, char *str, int **flag)
{
	if (!str[i + 1])
	{
		**flag = 0;
	}
	else if (str[i + 1] && str[i + 1] != '>')
	{
		i++;
		if (front(str, &i))
			**flag = 0;
	}
	else if (str[i + 1] && str[i + 1] == '>')
	{
		i += 2;
		if (front(str, &i))
			**flag = 0;
	}
	return (i);
}

int	part1(int i, char *str, int **flag)
{
	if (!str[i + 1])
		**flag = 0;
	else if (str[i + 1] && str[i + 1] != '<')
	{
		i++;
		if (back(str, i - 1) || front(str, &i))
			**flag = 0;
	}
	else if (str[i + 1] && str[i + 1] == '<')
	{
		i += 2;
		if (front(str, &i))
			**flag = 0;
	}
	return (i);
}

int	check(int i, char *str, int *flag)
{
	if (str[i] == '\'')
		i = chakerts_end(str, i);
	else if (str[i] == '\"')
		i = double_chakerts_end(str, i);
	else if (str[i] && str[i] == '<')
		i = part1(i, str, &flag);
	else if (str[i] && str[i] == '>')
		i = part1(i, str, &flag);
	return (0);
}
