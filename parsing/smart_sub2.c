#include "../../minishell.h"

int	ft_smart_sub_part1(char *rdl, int i, t_toks **hert)
{
	int	j;

	j = 0;
	i += 2;
	while (rdl[i] && rdl[i] == ' ')
	i++;
	j = i;
	if (rdl[i] == '\'')
	i = find_end_of_single_quote(rdl, i);
	else if (rdl[i] == '\"')
	i = find_end_of_double_quote(rdl, i);
	while (rdl[i] && rdl[i] != ' ')
	i++;
	ft_fill_red(hert, 2, ignore_quote(ft_substr(rdl, j, i - j)));
	return (i);
}

int	ft_smart_sub_part2(char *rdl, int i, t_toks **hert)
{
	int	j;

	j = 0;
	i += 2;
	while (rdl[i] && rdl[i] == ' ')
	i++;
	if (rdl[i] == '\'')
	i = find_end_of_single_quote(rdl, i);
	else if (rdl[i] == '\"')
	i = find_end_of_double_quote(rdl, i);
	j = i;
	while (rdl[i] && rdl[i] != ' ')
	i++;
	ft_fill_red(hert, 4, ignore_quote(ft_substr(rdl, j, i - j)));
	return (i);
}

int	ft_smart_sub_part3(char *rdl, int i, t_toks **hert)
{
	int	j;

	j = 0;
	i += 1;
	while (rdl[i] && rdl[i] == ' ')
	i++;
	j = i;
	if (rdl[i] == '\'')
	i = find_end_of_single_quote(rdl, i);
	else if (rdl[i] == '\"')
	i = find_end_of_double_quote(rdl, i);
	while (rdl[i] && !ft_strcrcmp(REDE, rdl[i]))
	i++;
	ft_fill_red(hert, 3, ignore_quote(ft_substr(rdl, j, i - j)));
	return (i);
}

int	ft_smart_sub_part4(char *rdl, int i, t_toks **hert)
{
	int	j;

	j = 0;
	i += 1;
	while (rdl[i] && rdl[i] == ' ')
	i++;
	j = i;
	while (rdl[i] && rdl[i] != ' ')
	i++;
	ft_fill_red(hert, 1, ignore_quote(ft_substr(rdl, j, i - j)));
	return (i);
}

int	ft_smart_sub_part5(char *rdl, int i, char	**tmp)
{
	int		j;
	char	*esim;
	char	*ptr;

	j = 0;
	j = i;
	while (rdl[i] != '<' && rdl[i] != '>' && rdl[i] != '\0')
	{
		if (rdl[i] == '\'')
		i = find_end_of_single_quote(rdl, i);
		else if (rdl[i] == '\"')
		i = find_end_of_double_quote(rdl, i);
		i++;
	}
	ptr = ft_substr(rdl, j, i - j);
	esim = *tmp;
	*tmp = ft_strjoin1(*tmp, ptr);
	free(esim);
	if (ptr)
		free(ptr);
	return (i);
}
