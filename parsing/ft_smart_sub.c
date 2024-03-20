#include "../../minishell.h"

void	ft_smart_sub( char *rdl, t_tokens **hert)
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
			i = ft_smart_sub_part1(rdl, i, hert);
		else if (rdl[i] && rdl[i + 1] && rdl[i] == '>' && rdl[i + 1] == '>')
			i = ft_smart_sub_part2(rdl, i, hert);
		else if (rdl[i] && rdl[i] == '>')
			i = ft_smart_sub_part3(rdl, i, hert);
		else if (rdl[i] && rdl[i] == '<')
			i = ft_smart_sub_part4(rdl, i, hert);
		else
			i = ft_smart_sub_part5(rdl, i, &tmp);
	}
	if (tmp)
	{
		(*hert)->cmd = smart_split(tmp, ' ');
		free(tmp);
	}
}
