/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:40:19 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/14 19:40:20 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	call_heredoc2(char *del, int len)
{
	if (len == 1)
		heredoc(del, 1);
	else
		heredoc(del, 0);
	len--;
	return (len);
}

void	call_heredoc(t_tokens **tk, int len)
{
	t_tokens	*token;
	t_chakerts	*red;

	token = *tk;
	while (token)
	{
		red = token->head_redct;
		while (token->head_redct)
		{
			if (token->head_redct && token->head_redct->flag == 2)
			{
				len = call_heredoc2(token->head_redct->del, len);
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

int	count_all_part2(t_tokens *token, t_count *count)
{
	if (token->head_redct->flag == 2)
		count->count_herdoc++;
	if (token->head_redct->next)
		token->head_redct = token->head_redct->next;
	else
		return (1);
	return (0);
}

t_count	*count_all(t_tokens **tok)
{	
	t_count		*count;
	t_tokens	*token;
	t_chakerts	*red1;

	token = *tok;
	count = malloc(sizeof(t_count));
	count->count_1 = 0;
	count->count_3 = 0;
	count->count_4 = 0;
	count->count_hrd = 0;
	while (token)
	{
	red1 = token->head_redct;
		while (token->head_redct->flag)
		{
			if (count_all_part2(token, count))
				break ;
		}
		token->head_redct = red1;
		if (token->next)
			token = token->next;
		else
			break ;
	}
	return (count);
}

void	func_red(t_tokens **token)
{
	t_count		*all_count;

	all_count = NULL;
	all_count = count_all((token));
	call_heredoc((token), all_count->count_hrd);
	free(all_count);
}
