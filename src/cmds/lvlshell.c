#include "../../minishell.h"

void	lvlshell(t_env **env)
{
	t_env	*res;
	int		tmp;

	res = get_env(env, "SHLVL");
	tmp = ft_atoi(res->value);
	free(res->value);
	res->value = ft_itoa(tmp + 1);
}