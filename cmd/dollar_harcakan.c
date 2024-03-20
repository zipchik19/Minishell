#include "../../minishell.h"

void	dollar_harcakan(void)
{
	char	*tiv;

	tiv = ft_itoa(g_exit_code);
	g_exit_code = 127;
	write(1, tiv, ft_strlen(tiv));
	write(1, ":", 1);
	write(1, "command not found", 18);
}
