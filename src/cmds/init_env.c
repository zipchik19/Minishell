#include "../../minishell.h"

void	init_env(char **env, t_env **cur_env)
{
	int		i;
	char	**env_split;

	i = 0;
	while (env[i])
	{
		env_split = ft_split(env[i], '=');
		(*cur_env)->key = env_split[0];
		(*cur_env)->value = env_split[1];
		free(env_split);
		if (ft_strcmp((*cur_env)->key, "OLDPWD"))
			(*cur_env)->flag = 0;
		else
			(*cur_env)->flag = 1;
		(*cur_env)->next = NULL;
		if (env[i + 1])
		{
			(*cur_env)->next = malloc(sizeof(t_env));
			cur_env = &(*cur_env)->next;
		}
		i++;
	}
	(*cur_env)->next = NULL;
}