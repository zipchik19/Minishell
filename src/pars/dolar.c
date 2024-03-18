/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dolar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:43:31 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/14 19:43:32 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*dollar_join(char *str, char *word, int i, int j)
{
	int		len;
	char	*new_str;
	char	*res;
	char	*tmp;

	len = ft_strlen(str);
	new_str = ft_substr(str, 0, i - 1);
	res = new_str;
	if (word)
	{
		new_str = ft_strjoin(new_str, word);
		free(res);
		res = new_str;
	}
	tmp = ft_substr(str, i + j - 1, len);
	res = new_str;
	new_str = ft_strjoin(new_str, tmp);
	free(tmp);
	free(res);
	free(str);
	return (new_str);
}

void	dollar2(char **str, int i, int j)
{
	char	*word;
	char	*back;

	word = ft_substr(*str, j, i - j);
	back = getenv(word);
	*str = dollar_join(*str, back, j, i - j + 1);
	free(word);
}

void	dollar(char **str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == '\'')
			i = chakerts_end(*str, i);
		if ((*str)[i] == '<' && (*str)[i + 1] && (*str)[i + 1] == '<' )
			i = till_spaces(*str, i + 2);
		if ((*str)[i] == '$' && (*str)[i + 1] == '?')
			i = i + 2;
		if ((*str)[i] == '$' && (*str)[i + 1] != ' '
			&& (*str)[i + 1] && (*str)[i + 1] != '\"')
		{
			j = ++i;
			while ((*str)[i] != ' ' && (*str)[i] && (*str)[i] != '$'
			&& (*str)[i] != '\"' && (*str)[i] != '/'
			&& (*str)[i] != '\'' && (*str)[i] != '=')
				i++;
			dollar2(str, i, j);
		}
		i++;
	}
}

void	dollar_harc(char **str)
{
	int		i;
	char	*exit_code;

	i = 0;
	exit_code = ft_itoa(g_exit_code);
	while ((*str)[i] && (*str)[i + 1])
	{
		if ((*str)[i] == '$' && (*str)[i + 1] == '?')
		{
			*str = dollar_join(*str, exit_code, i + 1, 2);
			i++;
		}
		else
			i++;
	}
	free (exit_code);
}
