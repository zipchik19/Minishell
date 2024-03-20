#include "../../minishell.h"

int	g_exit_code = 0;

void	main_part4(int *in_copy, int *out_copy)
{
	dup2(*in_copy, 0);
	dup2(*out_copy, 1);
	close(*out_copy);
}

int	main_part2(int *in_copy, int *out_copy, char **str)
{
	sig_control(1);
	*in_copy = dup(0);
	*out_copy = dup(1);
	*str = readline ("Minishell$> ");
	ctrl_d_check(*str);
	if (*str)
		add_history(*str);
	else
		return (1);
	return (0);
}

void	main_part3(t_tokens **token, t_env **s_env)
{			
	if (*token)
	{
		if ((*token)->token_count > 1)
			running_pipe(token, s_env);
		else
			running(token, s_env);
	}
}

int	main(int arg_nb, char **argv, char **env)
{
	char		*str;
	int			in_copy;
	int			out_copy;
	t_tokens	*token;
	t_env		*s_env;

	(void)arg_nb;
	(void)argv;
	s_env = malloc(sizeof(t_env));
	env_init(env, &s_env);
	shell_level(&s_env);
	while (1)
	{
		if (main_part2(&in_copy, &out_copy, &str))
			break ;
		if (sp_sp(str))
		{
			gen_parsing(&token, &s_env, &str);
			main_part3(&token, &s_env);
			main_part4(&in_copy, &out_copy);
			free_t_list(&token);
		}
		free(str);
	}
	return (0);
}
