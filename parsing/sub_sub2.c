#include "../../minishell.h"

int	sub_sub_part1(char *rdl, int i, t_toks **tok)
{
	int	j;

	j = 0;
	i += 2;
	while (rdl[i] && rdl[i] == ' ')
	i++;
	j = i;
	if (rdl[i] == '\'')
	i = end_of_1quote(rdl, i);
	else if (rdl[i] == '\"')
	i = end_of_2quote(rdl, i);
	while (rdl[i] && rdl[i] != ' ')
	i++;
	fill_reds(tok, 2, ignore_quotes(ft_substr(rdl, j, i - j)));
	return (i);
}

int	sub_sub_part2(char *rdl, int i, t_toks **tok)
{
	int	j;

	j = 0;
	i += 2;
	while (rdl[i] && rdl[i] == ' ')
	i++;
	if (rdl[i] == '\'')
	i = end_of_1quote(rdl, i);
	else if (rdl[i] == '\"')
	i = end_of_2quote(rdl, i);
	j = i;
	while (rdl[i] && rdl[i] != ' ')
	i++;
	fill_reds(tok, 4, ignore_quotes(ft_substr(rdl, j, i - j)));
	return (i);
}

int	sub_sub_part3(char *rdl, int i, t_toks **tok)
{
	int	j;

	j = 0;
	i += 1;
	while (rdl[i] && rdl[i] == ' ')
	i++;
	j = i;
	if (rdl[i] == '\'')
	i = end_of_1quote(rdl, i);
	else if (rdl[i] == '\"')
	i = end_of_2quote(rdl, i);
	while (rdl[i] && !ft_strcrcmp(REDE, rdl[i]))
	i++;
	fill_reds(tok, 3, ignore_quotes(ft_substr(rdl, j, i - j)));
	return (i);
}

int	sub_sub_part4(char *rdl, int i, t_toks **tok)
{
	int	j;

	j = 0;
	i += 1;
	while (rdl[i] && rdl[i] == ' ')
	i++;
	j = i;
	while (rdl[i] && rdl[i] != ' ')
	i++;
	fill_reds(tok, 1, ignore_quotes(ft_substr(rdl, j, i - j)));
	return (i);
}

int	sub_sub_part5(char *rdl, int i, char	**tmp)
{
	int		j;
	char	*var;
	char	*ptr;

	j = 0;
	j = i;
	while (rdl[i] != '<' && rdl[i] != '>' && rdl[i] != '\0')
	{
		if (rdl[i] == '\'')
		i = end_of_1quote(rdl, i);
		else if (rdl[i] == '\"')
		i = end_of_2quote(rdl, i);
		i++;
	}
	ptr = ft_substr(rdl, j, i - j);
	var = *tmp;
	*tmp = ft_strjoin1(*tmp, ptr);
	free(var);
	if (ptr)
		free(ptr);
	return (i);
}
