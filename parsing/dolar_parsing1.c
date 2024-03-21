#include "../../minishell.h"

int	find_end_of_single_quote(char *str, int i)
{
	i++;
	while (str[i] && str[i] != '\'' )
		i++;
	return (i);
}

int	find_end_of_double_quote(char *str, int i)
{	
	i++;
	while (str[i] && str[i] != '\"')
		i++;
	return (i);
}

void	dolar_pars_1(char **str, int i, int x)
{
	char	*world;
	char	*back;
	int		len;

	world = ft_substr(*str, x, i - x);
	back = getenv(world);
	*str = join_dolar_str(*str, back, x, i - x + 1);
	len = ft_strlen(str[0]);
	free(world);
}

void	dolar_pars(char **str)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == '\'')
			i = find_end_of_single_quote(*str, i);
		if ((*str)[i] == '<' && (*str)[i + 1] && (*str)[i + 1] == '<' )
			i = go_until_spasce(*str, i + 2);
		if ((*str)[i] == '$' && (*str)[i + 1] == '?')
			i = i + 2;
		if ((*str)[i] == '$' && (*str)[i + 1] != ' '
			&& (*str)[i + 1] && (*str)[i + 1] != '\"')
		{
			x = ++i;
			while ((*str)[i] != ' ' && (*str)[i] && (*str)[i] != '$'
			&& (*str)[i] != '"' && (*str)[i] != '/'
			&& (*str)[i] != '\'' && (*str)[i] != '=')
				i++;
			dolar_pars_1(str, i, x);
		}
		i++;
	}
}
