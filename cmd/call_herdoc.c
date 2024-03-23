/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_herdoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 08:49:58 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/23 08:51:07 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	call_heredoc_part2(char *del, int len)
{
	if (len == 1)
		heredoc(del, 1);
	else
		heredoc(del, 0);
	len--;
	return (len);
}

void	call_heredoc(t_toks **tk, int len)
{
	t_toks		*token;
	t_redirs	*red;

	token = *tk;
	while (token)
	{
		red = token->head_redct;
		while (token->head_redct)
		{
			if (token->head_redct && token->head_redct->flag == 2)
			{
				len = call_heredoc_part2(token->head_redct->del, len);
			}
			if (token->head_redct->next)
				token->head_redct = token->head_redct->next;
			else
				break ;
		}
		token->head_redct = red;
		if (token->next)
			token = token->next;
		else
			break ;
	}
	token = (*tk);
}
