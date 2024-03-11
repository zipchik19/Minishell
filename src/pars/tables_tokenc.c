#include "../../minishell.h"

int	ft_count_pipe(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			i = chakerts_end(str, i);
		else if (str[i] == '\"')
			i = double_chakerts_end(str, i);
		if (str[i] == '|')
			count++;
		i++;
	}
	return (count);
}

int	ft_count_tokens(char **token)
{
	int	i;

	i = 0;
	while (token[i])
		i++;
	return (i);
}

int	check_error(char **tokenized, char *str)
{
	int	count_pipe;
	int	count_tokens;

	count_pipe = ft_count_pipe(str);
	count_tokens = ft_count_tokens(tokenized);
	if (count_pipe && count_tokens - 1 != count_pipe)
	{
		g_exit_code = 258;
		write(2, "Minishell: syntax error near unexpected token `|'\n", 50);
		return (1);
	}
	return (0);
}

int	table_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}