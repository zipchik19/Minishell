/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:44:05 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/14 19:44:07 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	chakerts_add_back(t_chakerts **head, t_chakerts *new_node)
{
	t_chakerts	*tmp;

	tmp = *head;
	if ((*head)->flag == 0)
	{
		*head = new_node;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
}

void	fill_chakerts(t_tokens **token, int flag, char *str)
{
	t_tokens	*tok;
	t_chakerts	*chak;

	chak = NULL;
	tok = *token;
	if ((*token)->head_redct->flag == 0)
	{
		(*token)->head_redct->del = str;
		(*token)->head_redct->flag = flag;
		(*token)->head_redct->path = NULL;
		(*token)->head_redct->next = NULL;
	}
	else
	{
		chak = new_chakerts(flag, str, NULL);
		chakerts_add_back(&(tok)->head_redct, chak);
	}
}

void	tokens_add_back(t_tokens **head, t_tokens *new)
{
	t_tokens	*node;

	node = *head;
	if (!node)
	{
		*head = new;
		return ;
	}
	ft_lstlastt(node)->next = new;
}

void	fill_tokens(t_tokens **token, char **tokenized,
	int *hrd_c, int count_tok)
{
	int	i;

	i = 0;
	while (tokenized && tokenized[i])
	{
		tokens_add_back(token, new_tokens(tokenized[i], \
		NULL, hrd_c, count_tok));
		i++;
	}
}

void	tokenization(t_tokens **token, char **str)
{
	char	**tokenized;
	int		*hrd_c;
	int		tables_count;

	hrd_c = 0;
	tokenized = new_split(*str, '|');
	tables_count = table_len(tokenized);
	check_error(tokenized, str[0]);
	fill_tokens(token, tokenized, hrd_c, tables_count);
	free(tokenized);
	very_new_split(token);
	ignoring(token);
}
