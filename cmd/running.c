#include "../../minishell.h"

void	running_part1(t_tokens *token, t_env **l_env, t_env *env)
{
	int	j;

	j = 1;
	if (ft_strcmp1(token->cmd[0], "exit") == 0)
		exit_cmd(token->cmd);
	else if (ft_strcmp1(token->cmd[0], "pwd") == 0)
		pwd_cmd(l_env);
	else if (ft_strcmp1(token->cmd[0], "env") == 0)
		env_cmd(env);
	else if (ft_strcmp1(token->cmd[0], "export") == 0 && !token->cmd[1])
		only_export(l_env);
	else if (ft_strcmp1(token->cmd[0], "export") == 0)
	{
		while (token->cmd[j])
			export_cmd(l_env, token->cmd[j++]);
	}
	else if (ft_strcmp1(token->cmd[0], "cd") == 0)
		cd_cmd(l_env, token->cmd);
	else if (ft_strcmp1(token->cmd[0], "echo") == 0)
		echo_cmd(token->cmd);
	else if (ft_strcmp1(token->cmd[0], "unset") == 0)
		unset_cmd(l_env, token->cmd[1]);
	else
		execve_cmd(l_env, token->cmd);
}

void	running(t_tokens **tk, t_env **l_env)
{
	t_env		*env;
	t_tokens	*token;
	t_count		*all_count;
	int			j;

	env = *l_env;
	token = *tk;
	all_count = NULL;
	all_count = count_all(&token);
	token = *tk;
	j = 1;
	call_heredoc(tk, all_count->count_herdoc);
	call_redirections(tk);
	if (token->cmd && token->cmd[0])
		running_part1(token, l_env, env);
	free(all_count);
}
