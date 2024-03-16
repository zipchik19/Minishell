#include "../../minishell.h"

void	ft_execve_cmd_2(char **splited_path,
			char **str, t_env **env, char *new_str)
{
	char	**mx_env;
	int		pid;

	pid = 0;
	mx_env = t_env_to_matrix(env);
	pid = fork();
	if (pid == 0)
	{
		sig_control(0);
		new_str = cheack_access(splited_path, str, mx_env);
		ft_execv(new_str, mx_env, str);
	}
	else
		signal_execve();
	matrix_free(mx_env);
	matrix_free(splited_path);
}

void	execve_cmd(t_env **env, char **str)
{
	t_env	*path;
	char	**splited_path;
	char	*new_str;

	path = get_env(env, "PATH");
	if (path)
	{
		splited_path = ft_split(path->value, ':');
		new_str = ft_strjoin("/", str[0]);
		create_the_paths(splited_path, new_str);
		free(new_str);
		ft_execve_cmd_2(splited_path, str, env, new_str);
	}
	else
		error_msg(str[0], "No such file or directory", 127);
	return ;
}

void	signal_execve(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	processing_status(1);
}