/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_pars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:02:47 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/23 11:24:55 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	end1quote(char *str, int i)
{
	while (str[i] && str[i] != '\'')
		i++;
	return (str[i] == '\'');
}

int	end2quote(char *str, int i)
{
	while (str[i] && str[i] != '\"')
		i++;
	return (str[i] == '\"');
}

void	count_quotes(char *str, int *single_count, int *double_count)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			(*single_count)++;
			if (!end1quote(str, i))
				(*single_count)++;
		}
		else if (str[i] == '\"')
		{
			(*double_count)++;
			if (!end2quote(str, i))
				(*double_count)++;
		}
		i++;
	}
}

int	quotes_pars(char *str)
{
	int	single_count;
	int	double_count;

	single_count = 0;
	double_count = 0;
	count_quotes(str, &single_count, &double_count);
	if (single_count % 2)
	{
		print_error("\'", "Token error", 1);
		return (1);
	}
	if (double_count % 2)
	{
		print_error("\"", "Token error", 1);
		return (1);
	}
	return (0);
}
