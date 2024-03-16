/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:38:02 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/16 13:55:04 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	call_redirections_part2(t_tokens **tk, t_count *len)
{	
	t_chakerts	*red;
	t_tokens	*token;

	token = *tk;
	red = token->head_redct;
	while (token->head_redct && token->head_redct->flag)
	{
		do_the_job(token->head_redct, len);
		if (token->head_redct->next)
			token->head_redct = token->head_redct->next;
		else
		{
			token->head_redct = red;
			token = *tk;
			free(len);
			return (1);
		}
	}
	token->head_redct = red;
	token = *tk;
	return (0);
}

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

void	call_redirections(t_tokens **tk)
{
	t_chakerts	*red;
	t_tokens	*token;
	t_count		*len;
	int			i;

	token = *tk;
	i = 1;
	while (token)
	{
		len = count_redirect(&token);
		red = token->head_redct;
		if (call_redirections_part2(&token, len))
			break ;
		token->head_redct = red;
		if (token->next)
		token = token->next;
		else
		{
			free(len);
			break ;
		}
		free(len);
	}
	token = (*tk);
}