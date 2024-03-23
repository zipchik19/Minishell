/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:30:23 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/23 11:30:25 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	word_count(char *str, char delim)
{
	int	prev_del;
	int	i;
	int	count;

	i = 0;
	count = 0;
	prev_del = 1;
	while (str[i])
	{
		if (str[i] && str[i] == '\"')
			i = end_of_2quote(str, i);
		if (str[i] && str[i] == '\'')
			i = end_of_1quote(str, i);
		if (str[i] == delim)
			prev_del = 1;
		else if (prev_del)
			count++;
		if (str[i] != delim)
			prev_del = 0;
		i++;
	}
	return (count);
}

static char	*word_fill( char *s, size_t start, size_t len)
{
	size_t	i;
	char	*word;

	i = 0;
	word = malloc(len + 1);
	if (word == 0)
		return (0);
	while (i < len)
	{
		word[i] = s[start + i];
		i++;
	}
	word[i] = 0;
	return (word);
}

static void	*str_free(char **str, size_t i)
{
	size_t	j;

	j = 0;
	while (i >= j)
	{
		free(str[j]);
		++j;
	}
	free(str);
	return (0);
}

char	**smart_split(char *s, char c)
{
	int		start;
	int		end;
	int		i;
	char	**str;

	i = -1;
	start = 0;
	str = malloc(sizeof (char *) * (word_count(s, c) + 1));
	if (str == 0)
		return (0);
	while (++i < word_count(s, c))
	{
		end = smart_split_part1(start, s, c, i);
		start = end;
		end = smart_split_part2(end, s, c);
		str[i] = word_fill(s, start, end - start);
		if (!str[i])
			str_free(str, i);
		start = end;
	}
	str[i] = 0;
	return (str);
}
