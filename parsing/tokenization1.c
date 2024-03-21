#include "../../minishell.h"

void	fill_reds(t_toks **tok, int flag, char *str)
{
	t_toks		*tk;
	t_redirs	*red;

	red = NULL;
	tk = *tok;
	if ((*tok)->head_redct->flag == 0)
	{
		(*tok)->head_redct->del = str;
		(*tok)->head_redct->flag = flag;
		(*tok)->head_redct->pathname = NULL;
		(*tok)->head_redct->next = NULL;
	}
	else
	{
		red = new_redirs(flag, str, NULL);
		redirs_add_back(&(tk)->head_redct, red);
	}
}

void	redirs_add_back(t_redirs **head, t_redirs *new_node)
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

void	toks_add_back(t_toks **head, t_toks *new)
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

void	fill_toks(t_toks **tok, char **tokenized,
	int *hrd_c, int count_token)
{
	int	i;

	i = 0;
	while (tokenized && tokenized[i])
	{
		toks_add_back(tok, new_toks(tokenized[i],
				NULL, hrd_c, count_token));
		i++;
	}
}

void	tokenization(t_toks **tok, char **str)
{
	char	**tokenized;
	int		*hrd_c;
	int		count_token;

	hrd_c = 0;
	tokenized = smart_split(*str, '|');
	count_token = matrix_len(tokenized);
	error_msgs(tokenized, str[0]);
	fill_toks(tok, tokenized, hrd_c, count_token);
	free(tokenized);
	other_smart_split(tok);
	tf_norm(tok);
}
