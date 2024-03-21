#include "../../minishell.h"

void	ft_fill_red(t_toks **token, int flag, char *str)
{
	t_toks	*tk;
	t_redirs	*red;

	red = NULL;
	tk = *token;
	if ((*token)->head_redct->flag == 0)
	{
		(*token)->head_redct->del = str;
		(*token)->head_redct->flag = flag;
		(*token)->head_redct->pathname = NULL;
		(*token)->head_redct->next = NULL;
	}
	else
	{
		red = new_t_redirs(flag, str, NULL);
		t_redirs_add_back(&(tk)->head_redct, red);
	}
}

void	t_redirs_add_back(t_redirs **head, t_redirs *new_node)
{
	t_redirs	*tmp;

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

void	t_toks_add_back(t_toks **head, t_toks *new)
{
	t_toks	*node;

	node = *head;
	if (!node)
	{
		*head = new;
		return ;
	}
	ft_lstlast1(node)->next = new;
}

void	fill_t_token(t_toks **token, char **tokenized,
	int *hrd_c, int count_token)
{
	int	i;

	i = 0;
	while (tokenized && tokenized[i])
	{
		t_toks_add_back(token, new_t_toks(tokenized[i],
				NULL, hrd_c, count_token));
		i++;
	}
}

void	tokenization(t_toks **token, char **str)
{
	char	**tokenized;
	int		*hrd_c;
	int		count_token;

	hrd_c = 0;
	tokenized = smart_split(*str, '|');
	count_token = matrix_len(tokenized);
	check_error(tokenized, str[0]);
	fill_t_token(token, tokenized, hrd_c, count_token);
	free(tokenized);
	smart_smart_split(token);
	ftft(token);
}
