#include "../../minishell.h"

void	unset_cmd(t_env **l_env, char *new_key)
{
	t_env	*env;
	t_env	*rtv;

	env = *l_env;
	rtv = 0;
	if (!new_key)
		return ;
	if (exp_pars(new_key))
		return ;
	if (find_key(l_env, new_key))
	{
		rtv = get_env(l_env, new_key);
		while (env->next != rtv)
			env = env->next;
		env->next = rtv->next;
		free_node(&rtv);
	}
}

void	echo_cmd(char **str)
{
	int	i;
	int	flag;

	flag = -1;
	i = 0;
	if (str[1] && str[1][i] == '-')
		i += echo_cmd_1(str[1], &flag);
	if (flag == 0)
	{
		i = 2;
		while (str[i])
		{
			printf("%s", str[i]);
				i++;
		}
	}
	else if (ft_strcmp(str[1], "-n"))
		echo_cmd_2(str, i);
	else
		echo_cmd_3(str, i);
}
