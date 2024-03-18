/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:44:11 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/14 19:44:12 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	sub1(char *line, int i, t_tokens **queue)
{
	int	j;

	j = 0;
	i += 2;
	while (line[i] && line[i] == ' ')
		i++;
	j = i;
	if (line[i] == '\'')
		i = chakerts_end(line, i);
	else if (line[i] == '\"')
		i = double_chakerts_end(line, i);
	while (line[i] && line[i] != ' ')
		i++;
	fill_chakerts(queue, 2, ignore_chak(ft_substr(line, j, i - j)));
	return (i);
}

int	sub2(char *line, int i, t_tokens **queue)
{
	int	j;

	j = 0;
	i += 2;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == '\'')
		i = chakerts_end(line, i);
	else if (line[i] == '\"')
		i = double_chakerts_end(line, i);
	j = i;
	while (line[i] && line[i] != ' ')
		i++;
	fill_chakerts(queue, 4, ignore_chak(ft_substr(line, j, i - j)));
	return (i);
}

int	sub3(char *line, int i, t_tokens **queue)
{
	int	j;

	j = 0;
	i += 1;
	while (line[i] && line[i] == ' ')
		i++;
	j = i;
	if (line[i] == '\'')
		i = chakerts_end(line, i);
	else if (line[i] == '\"')
		i = double_chakerts_end(line, i);
	while (line[i] && !ft_strcharcmp(REDE, line[i]))
		i++;
	fill_chakerts(queue, 3, ignore_chak(ft_substr(line, j, i - j)));
	return (i);
}

int	sub4(char *line, int i, t_tokens **queue)
{
	int	j;

	j = 0;
	i += 1;
	while (line[i] && line[i] == ' ')
		i++;
	j = i;
	while (line[i] && line[i] != ' ')
		i++;
	fill_chakerts(queue, 1, ignore_chak(ft_substr(line, j, i - j)));
	return (i);
}

int	sub5(char *line, int i, char	**tmp)
{
	int		j;
	char	*esim;
	char	*ptr;

	j = 0;
	j = i;
	while (line[i] != '<' && line[i] != '>' && line[i] != '\0')
	{
		if (line[i] == '\'')
			i = chakerts_end(line, i);
		else if (line[i] == '\"')
			i = double_chakerts_end(line, i);
		i++;
	}
	ptr = ft_substr(line, j, i - j);
	esim = *tmp;
	*tmp = ft_strjoin2(*tmp, ptr);
	free(esim);
	if (ptr)
		free(ptr);
	return (i);
}
