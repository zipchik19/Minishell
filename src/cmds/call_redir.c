/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:38:02 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/14 19:38:04 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	do_the_job(t_chakerts *token, t_count *len)
{
	if (token->flag == 1)
	{
		if (len->count_1 == 1)
			redirection_input(token->del, 1);
		else
			redirection_input(token->del, 0);
		len->count_1--;
	}
	if (token->flag == 3)
	{
		if (len->count_3 == 1)
			redirection_output(token->del, 1);
		else
			redirection_output(token->del, 0);
		len->count_3--;
	}
	if (token->flag == 4)
	{
		if (len->count_4 == 1)
			redirection_output_append(token->del, 1);
		else
			redirection_output_append(token->del, 0);
		len->count_4--;
	}	
}

void	call_redirections6(t_tokens **tk, t_count *len)
{
	t_chakerts	*red;
	t_tokens	*token;
	int			i;

	token = *tk;
	i = 1;
	red = token->head_redct;
	while (token->head_redct && token->head_redct->flag)
	{
		do_the_job(token->head_redct, len);
		if (token->head_redct->next)
			token->head_redct = token->head_redct->next;
		else
			break ;
		i++;
	}
	token->head_redct = red;
	free(len);
	token = (*tk);
}
