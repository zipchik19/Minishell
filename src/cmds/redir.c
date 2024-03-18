/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:41:09 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/16 16:41:51 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	status_check(char *file, char *s)
{
	if (g_exit_code == -14)
	{
		g_exit_code = 1;
		free(file);
		free(s);
		return (1);
	}
	return (0);
}

int	count_redirect_part2(t_tokens *token, t_count **count)
{
	if (token->head_redct->flag == 1)
		(*count)->count_1++;
	if (token->head_redct->flag == 2)
		(*count)->count_hrd++;
	if (token->head_redct->flag == 3)
		(*count)->count_3++;
	if (token->head_redct->flag == 4)
		(*count)->count_4++;
	if (token->head_redct->next)
		token->head_redct = token->head_redct->next;
	else
		return (1);
	return (0);
}

t_count	*count_redirect(t_tokens **tk)
{
	t_count		*count;
	t_tokens	*token;
	t_chakerts	*red1;

	token = *tk;
	count = malloc(sizeof(t_count));
	count->count_1 = 0;
	count->count_3 = 0;
	count->count_4 = 0;
	count->count_hrd = 0;
	red1 = token->head_redct;
	while (token->head_redct->flag)
	{
		if (count_redirect_part2(token, &count))
			break ;
	}
	token->head_redct = red1;
	return (count);
}
