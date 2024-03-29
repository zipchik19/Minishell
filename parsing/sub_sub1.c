/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_sub1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:03:44 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/23 11:03:45 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	sub_sub( char *rdl, t_toks **tok)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = 0;
	while (rdl[i])
	{
		while (rdl[i] && rdl[i] == ' ')
		i++;
		if (rdl[i] && rdl[i + 1] && rdl[i] == '<' && rdl[i + 1] == '<')
			i = sub_sub_part1(rdl, i, tok);
		else if (rdl[i] && rdl[i + 1] && rdl[i] == '>' && rdl[i + 1] == '>')
			i = sub_sub_part2(rdl, i, tok);
		else if (rdl[i] && rdl[i] == '>')
			i = sub_sub_part3(rdl, i, tok);
		else if (rdl[i] && rdl[i] == '<')
			i = sub_sub_part4(rdl, i, tok);
		else
			i = sub_sub_part5(rdl, i, &tmp);
	}
	if (tmp)
	{
		(*tok)->cmd = smart_split(tmp, ' ');
		free(tmp);
	}
}
