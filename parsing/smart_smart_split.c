#include "../../minishell.h"

int	any_quote(char *str, int i)
{
	if (str[i] == '\'')
	i = find_end_of_single_quote(str, i);
	else if (str[i] == '\"')
		i = find_end_of_double_quote(str, i);
	return (i);
}

char	*ignore_quote_part2(char *str, int i, int j)
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

char	*ignore_quote(char *str)
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
	return (ignore_quote_part2(str, i, j));
}

void	smart_smart_split(t_tokens **token)
{
	t_tokens	*tk;

	tk = *token;
	while (tk)
	{
		ft_smart_sub(tk->rdl, &tk);
		tk = tk->next;
	}
}
