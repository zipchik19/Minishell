#include "../../minishell.h"

int	g_exit_code = 0;

int	main2(int *in_cpy, int *out_cpy, char **str)
{
	//sig_control(1);
	*in_cpy = dup(0);
	*out_cpy = dup(1);
	*str = readline ("Minishell: ");
	ctrl_d(*str);
	if (*str)
		add_history(*str);
	else
		return (1);
	return (0);
}

// void	main3(t_tokens **token, t_env **s_env)
// {			
// 	if (*token)
// 	{
// 		if ((*token)->token_count > 1)
// 			// running_pipe(token, s_env);
// 		else
// 			// running(token, s_env);
// 	}
// }

void	main4(int *in_cpy, int *out_cpy)
{
	dup2(*in_cpy, 0);
	dup2(*out_cpy, 1);
	close(*out_cpy);
}

int	main(int argc, char **argv, char **env)
{
	char		*str;
	int			in_cpy;
	int			out_cpy;
	t_tokens	*token;
	t_env		*cur_env;
	(void)argc;
	(void)argv;
	(void)**env;
	cur_env = malloc(sizeof(t_env));
	init_env(env, &cur_env);
	lvlshell(&cur_env); 
	
	while (1)
	{
		if (main2(&in_cpy, &out_cpy, &str))
			break ;
		if (trim_sp(str))
		{
			pars1(&token, &cur_env, &str);
		//	main3(&token, &cur_env);
			main4(&in_cpy, &out_cpy);
		// 	free_t_list(&token);
		}
		free(str);
	}
	return (0);
}