/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_toks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:43:37 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/14 19:43:40 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_chakerts	*new_chakerts(int flag, char *del, char *pathname)
{
	t_chakerts	*new_red;

	new_red = malloc(sizeof(t_chakerts));
	new_red->flag = flag;
	new_red->del = del;
	new_red->path = pathname;
	new_red->next = NULL;
	return (new_red);
}

t_tokens	*ft_lstlastt(t_tokens *lst)
{
	if (lst == NULL)
		return (0);
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

t_tokens	*new_tokens(char *rdl, char **cmd, int *hrd_count, int count_token)
{
	t_tokens	*new_node;

	(void)cmd;
	(void)hrd_count;
	new_node = malloc(sizeof(t_tokens));
	new_node->rdl = rdl;
	new_node->cmd = NULL;
	new_node->head_redct = NULL;
	new_node->head_redct = malloc(sizeof(t_chakerts));
	new_node->head_redct->flag = 0;
	new_node->head_redct->del = NULL;
	new_node->head_redct->path = NULL;
	new_node->head_redct->next = NULL;
	new_node->table_count = count_token;
	new_node->next = NULL;
	return (new_node);
}

void	ignoring(t_tokens **token)
{
	int			i;
	t_tokens	*tok;

	i = 0;
	tok = *token;
	while (tok)
	{
		i = 0;
		while (tok && tok->cmd && tok->cmd[i])
		{
			tok->cmd[i] = ignore_chak(tok->cmd[i]);
			i++;
		}
		tok = tok->next;
	}
}
