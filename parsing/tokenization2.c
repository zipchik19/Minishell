/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:07:19 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/23 11:07:21 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_redirs	*new_redirs(int flag, char *del, char *pathname)
{
	t_redirs	*new_red;

	new_red = malloc(sizeof(t_redirs));
	new_red->flag = flag;
	new_red->del = del;
	new_red->pathname = pathname;
	new_red->next = NULL;
	return (new_red);
}

t_toks	*new_toks(char *rdl, char **cmd,
	int *hrd_count, int count_tok)
{
	t_toks	*new_node;

	(void)cmd;
	(void)hrd_count;
	new_node = malloc(sizeof(t_toks));
	new_node->rdl = rdl;
	new_node->cmd = NULL;
	new_node->head_redct = NULL;
	new_node->head_redct = malloc(sizeof(t_redirs));
	new_node->head_redct->flag = 0;
	new_node->head_redct->del = NULL;
	new_node->head_redct->pathname = NULL;
	new_node->head_redct->next = NULL;
	new_node->token_count = count_tok;
	new_node->next = NULL;
	return (new_node);
}

t_toks	*ft_lstlast1(t_toks *lst)
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
