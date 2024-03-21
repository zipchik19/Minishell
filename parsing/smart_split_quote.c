#include "../../minishell.h"

// int	any_quote(char *str, int i)
// {
// 	if (str[i] == '\'')
// 	i = end_of_1quote(str, i);
// 	else if (str[i] == '\"')
// 		i = end_of_2quote(str, i);
// 	return (i);
// }

char	*ignore_quoteee(char *str, int i, int j)
{
	char	*tmp;

	tmp = NULL;
	tmp = malloc(sizeof(char *) * (i - j + 1));
	tmp[i - j] = 0;
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != '\'' && str[i] != '\"')
		{
			tmp[j] = str[i];
			j++;
		}
		i++;
	}
	free (str);
	return (tmp);
}

char	*ignore_quotes(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			j++;
		i++;
	}
	return (ignore_quoteee(str, i, j));
}

void	other_smart_split(t_toks **token)
{
	t_toks	*tk;

	tk = *token;
	while (tk)
	{
		smart_sub(tk->rdl, &tk);
		tk = tk->next;
	}
}
