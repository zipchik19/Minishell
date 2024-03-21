#include "../../minishell.h"

void	print_exp(char *str, int z)
{
	(void)str;
	g_exit_code = z;
	printf("bash: export: `%s': not a valid identifier\n", str);
}

int	exp_pars(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if ((str[i] && (ft_strcrcmp(METAE, str[i])))
			|| (str[i] == '+' && i != len - 1)
			|| (str[i] >= '0' && str[i] <= '9'))
		{
			print_exp(str, 1);
			return (1);
		}
		i++;
	}
	return (0);
}
