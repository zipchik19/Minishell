#include "../../minishell.h"

void	dolar_harc(char **str)
{
	int		i;
	char	*num;

	i = 0;
	num = ft_itoa(g_exit_code);
	while ((*str)[i] && (*str)[i + 1])
	{
		if ((*str)[i] == '$' && (*str)[i + 1] == '?')
		{
			*str = dolars_join(*str, num, i + 1, 2);
			i++;
		}
		else
			i++;
	}
	free (num);
}
