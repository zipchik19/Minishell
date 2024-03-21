#include "../../minishell.h"

void	smart_sub( char *rdl, t_toks **hert)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = 0;
	while (rdl[i])
	{
		while (rdl[i] && rdl[i] == ' ')
		i++;
		if (rdl[i] && rdl[i + 1] && rdl[i] == '<' && rdl[i + 1] == '<')
			i = smart_sub_part1(rdl, i, hert);
		else if (rdl[i] && rdl[i + 1] && rdl[i] == '>' && rdl[i + 1] == '>')
			i = smart_sub_part2(rdl, i, hert);
		else if (rdl[i] && rdl[i] == '>')
			i = smart_sub_part3(rdl, i, hert);
		else if (rdl[i] && rdl[i] == '<')
			i = smart_sub_part4(rdl, i, hert);
		else
			i = smart_sub_part5(rdl, i, &tmp);
	}
	if (tmp)
	{
		(*hert)->cmd = smart_split(tmp, ' ');
		free(tmp);
	}
}
