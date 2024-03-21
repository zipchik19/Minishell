#include "../../minishell.h"

int	g_exit_code = 0;

void	main4(int *in_cpy, int *out_cpy)
{
	dup2(*in_cpy, 0);
	dup2(*out_cpy, 1);
	close(*out_cpy);
}

int	main2(int *in_cpy, int *out_cpy, char **str)
{
	sig_control(1);
	*in_cpy = dup(0);
	*out_cpy = dup(1);
	*str = readline ("Minishell$> ");
	ctrl_d_check(*str);
	if (*str)
		add_history(*str);
	else
		return (1);
	return (0);
}

void	main3(t_toks **tok, t_env **s_env)
{			
	if (*tok)
	{
		if ((*tok)->token_count > 1)
			running_pipe(tok, s_env);
		else
			running(tok, s_env);
	}
}

int	main(int argc, char **argv, char **env)
{
	char		*str;
	int			in_cpy;
	int			out_cpy;
	t_toks		*tok;
	t_env		*s_env;

	(void)argc;
	(void)argv;
	s_env = malloc(sizeof(t_env));
	env_init(env, &s_env);
	shell_level(&s_env);
	while (1)
	{
		if (main2(&in_cpy, &out_cpy, &str))
			break ;
		if (sp_trim(str))
		{
			main_pars(&tok, &s_env, &str);
			main3(&tok, &s_env);
			main4(&in_cpy, &out_cpy);
			free_toks(&tok);
		}
		free(str);
	}
	return (0);
}
