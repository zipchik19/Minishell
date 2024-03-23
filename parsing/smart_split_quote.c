/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_split_quote.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:25:10 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/23 15:31:00 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	handle_quote(char c, int *single_quote_found, int *double_quote_found)
{
	if (c == '\'')
	{
		if (!*double_quote_found)
		{
			*single_quote_found = !*single_quote_found;
			return (0);
		}
	}
	else if (c == '\"')
	{
		if (!*single_quote_found)
		{	
			*double_quote_found = !*double_quote_found;
			return (0);
		}
	}
	return (1);
}

void	process_quotes_and_copy(char *str, char *result, \
		int *single_quote_found, int *double_quote_found)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (handle_quote(str[i], single_quote_found, double_quote_found))
			result[j++] = str[i];
		i++;
	}
	result[j] = '\0';
}

char	*ignore_quotes(char *str)
{
	int		len;
	char	*result;
	int		single_quote_found;
	int		double_quote_found;

	len = strlen(str);
	result = (char *) malloc(len + 1);
	single_quote_found = 0;
	double_quote_found = 0;
	if (result == NULL)
		return (NULL);
	process_quotes_and_copy(str, result, \
			&single_quote_found, &double_quote_found);
	return (result);
}

void	other_smart_split(t_toks **tok)
{
	t_toks	*tk;

	tk = *tok;
	while (tk)
	{
		sub_sub(tk->rdl, &tk);
		tk = tk->next;
	}
}
