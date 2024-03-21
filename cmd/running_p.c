#include "../../minishell.h"

void	running_p_part1(t_toks *token, t_env **l_env, t_env *env)
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
		execve_cmd2(l_env, token->cmd);
}

void	running_p(t_toks **token, t_env **l_env, int (*fd)[2], int i)
{
	t_env		*env;
	t_toks	*tk;
	int			j;
	t_count		*all_count;

	env = *l_env;
	tk = *token;
	j = 1;
	all_count = NULL;
	all_count = count_redirect((token));
	child_pr(fd, i, (*token)->token_count);
	call_redirections6((token), all_count);
	if ((*token)->cmd && (*token)->cmd[0])
		running_p_part1(tk, l_env, env);
}
