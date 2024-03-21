#include "../../minishell.h"

int	end_of_1quote(char *str, int i)
{
	i++;
	while (str[i] && str[i] != '\'' )
		i++;
	return (i);
}

int	end_of_2quote(char *str, int i)
{	
	i++;
	while (str[i] && str[i] != '\"')
		i++;
	return (i);
}

void	dolar_parsss(char **str, int i, int x)
{
	char	*world;
	char	*back;
	int		len;

	world = ft_substr(*str, x, i - x);
	back = getenv(world);
	*str = dolars_join(*str, back, x, i - x + 1);
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
			i = end_of_1quote(*str, i);
		if ((*str)[i] == '<' && (*str)[i + 1] && (*str)[i + 1] == '<' )
			i = skip_find_sp_idx(*str, i + 2);
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
			dolar_parsss(str, i, x);
		}
		i++;
	}
}
