/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:46:12 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/14 19:46:15 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_part2(t_tokens **token)
{
	t_chakerts	*hrd_next;

	hrd_next = (*token)->head_redct->next;
	if ((*token)->head_redct->del)
		free((*token)->head_redct->del);
	free((*token)->head_redct);
	(*token)->head_redct = hrd_next;
}

void	free_t_list(t_tokens **token)
{
	int			i;
	t_tokens	*next;

	i = 0;
	while ((*token))
	{
		i = 0;
		next = (*token)->next;
		if ((*token)->rdl)
			free((*token)->rdl);
		if ((*token)->cmd)
		{
			while ((*token)->cmd[i])
				free((*token)->cmd[i++]);
		}
		while ((*token)->head_redct && (*token)->head_redct->flag)
			free_part2(token);
		free((*token)->head_redct);
		next = (*token)->next;
		free((*token)->cmd);
		free(*token);
		(*token) = next;
	}
	token = NULL;
}

void	*str_free(char **str, size_t i)
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

void	fd_close(int (*fd)[2], int count)
{
	int	i;

	i = 0;
	while (i < count - 1)
	{
		close(fd[i][0]);
		close(fd[i][1]);
		i++;
	}
}
