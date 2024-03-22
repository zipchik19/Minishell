#include "../../minishell.h"

void	tf_norm(t_toks **tok)
{
    t_toks *tk = *tok;
    while (tk)
    {
        int i = 0;
        while (tk->cmd && tk->cmd[i])
        {
            char* modified_cmd = ignore_quotes(tk->cmd[i]);
            if (modified_cmd != NULL)
			{
                free(tk->cmd[i]);
                tk->cmd[i] = modified_cmd;
            }
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

int	tok_count(char **tok)
{
	int	i;

	i = 0;
	while (tok[i])
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
