#include "../../minishell.h"

void	tf_norm(t_toks **token)
{
	int			i;
	t_toks	*tk;

	i = 0;
	tk = *token;
	while (tk)
	{
		i = 0;
		while (tk && tk->cmd && tk->cmd[i])
		{
			tk->cmd[i] = ignore_quotes(tk->cmd[i]);
			i++;
		}
		tk = tk->next;
	}
}

int	pipe_count(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			i = end_of_1quote(str, i);
		else if (str[i] == '\"')
			i = end_of_2quote(str, i);
		if (str[i] == '|')
			count++;
		i++;
	}
	return (count);
}

int	tok_count(char **token)
{
	int	i;

	i = 0;
	while (token[i])
		i++;
	return (i);
}

int	error_msgs(char **tokenized, char *str)
{
	int	count_pipe;
	int	count_toks;

	count_pipe = pipe_count(str);
	count_toks = tok_count(tokenized);
	if (count_pipe && count_toks - 1 != count_pipe)
	{
		g_exit_code = 258;
		write(2, "Minishell: syntax error near unexpected token `|'\n", 50);
		return (1);
	}
	return (0);
}
