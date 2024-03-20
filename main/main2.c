#include "../../minishell.h"

void	ctrl_d_check(char *s)
{
	if (!s)
	{
		write(1, "exit\n", 5);
		exit(g_exit_code);
	}
}

int	sp_sp(char *str)
{
	char	*rt;

	rt = ft_strtrim(str, " ");
	if (rt == NULL)
		return (0);
	else
	{
		free(rt);
		return (1);
	}
}
