#include "../../minishell.h"

void	print_exp(char *str, char *val, char *cmd)
{
	(void)str;
	g_exit_code = 1;
	if(!ft_strcmp1(cmd, "export"))
	{
		if (val)
			printf("miniHell: export: `%s=%s': not a valid identifier\n", str, val);
		else
			printf("miniHell: export: `%s': not a valid identifier\n", str);
	}
	if(!ft_strcmp1(cmd, "unset"))
	{
		if (val)
			printf("miniHell: unset: `%s=%s': not a valid identifier\n", str, val);
		else
			printf("miniHell: unset: `%s': not a valid identifier\n", str);
	}
}

int	exp_pars(char *str, char *val, char *cmd)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if ((str[i] && (ft_strcrcmp(METAE, str[i])))
			|| (str[i] == '+' && i != len - 1) || str[0] == '=' || (str[0] >= '0' && str[0] <= '9'))
		{
			print_exp(str, val, cmd);
			return (1);
		}
		i++;
	}
	return (0);
}
