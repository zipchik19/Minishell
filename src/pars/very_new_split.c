/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   very_new_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:44:19 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/14 19:44:20 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	sub_general(char *line, t_tokens **queue)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = 0;
	while (line[i])
	{
		while (line[i] && line[i] == ' ')
			i++;
		if (line[i] && line[i + 1] && line[i] == '<' && line[i + 1] == '<')
			i = sub1(line, i, queue);
		else if (line[i] && line[i + 1] && line[i] == '>' && line[i + 1] == '>')
			i = sub2(line, i, queue);
		else if (line[i] && line[i] == '>')
			i = sub3(line, i, queue);
		else if (line[i] && line[i] == '<')
			i = sub4(line, i, queue);
		else
			i = sub5(line, i, &tmp);
	}
	if (tmp)
	{
		(*queue)->cmd = new_split(tmp, ' ');
		free(tmp);
	}
}

void	very_new_split(t_tokens **token)
{
	t_tokens	*tok;

	tok = *token;
	while (tok)
	{
		sub_general(tok->rdl, &tok);
		tok = tok->next;
	}
}
