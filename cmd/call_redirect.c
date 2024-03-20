#include "../../minishell.h"

int	call_redirections_part2(t_tokens **tk, t_count *len)
{	
	t_redirects	*red;
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

void	call_redirections(t_tokens **tk)
{
	t_redirects	*red;
	t_tokens	*token;
	t_count		*len;
	int			i;

	token = *tk;
	i = 1;
	while (token)
	{
		len = count_red(&token);
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

void	call_redirections6(t_tokens **tk, t_count *len)
{
	t_redirects	*red;
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

int	count_redirect_part2(t_tokens *token, t_count **count)
{
	if (token->head_redct->flag == 1)
		(*count)->count_1++;
	if (token->head_redct->flag == 2)
		(*count)->count_herdoc++;
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
	t_redirects	*red1;

	token = *tk;
	count = malloc(sizeof(t_count));
	count->count_1 = 0;
	count->count_3 = 0;
	count->count_4 = 0;
	count->count_herdoc = 0;
	red1 = token->head_redct;
	while (token->head_redct->flag)
	{
		if (count_redirect_part2(token, &count))
			break ;
	}
	token->head_redct = red1;
	return (count);
}
