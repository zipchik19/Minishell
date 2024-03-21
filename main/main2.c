#include "../../minishell.h"

void	ctrl_d_check(char *s)
{
	if (!s)
	{
		write(1, "exit\n", 5);
		exit(g_exit_code);
	}
}

int	sp_trim(char *str)
{
	char	*res;

	res = ft_strtrim(str, " ");
	if (res == NULL)
		return (0);
	else
	{
		free(res);
		return (1);
	}
}
