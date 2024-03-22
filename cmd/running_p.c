#include "../../minishell.h"

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
		running_part1(tk, l_env, env);
}
