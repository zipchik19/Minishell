#include "../../minishell.h"

int	exit_cmd(char **c)
{
	char		*str;

	if (!c[1])
	{
		printf("exit\n");
		exit(0);
	}
	if (!ft_isdigit(c[1]) || (c[2] && !ft_isdigit(c[1])))
	{
		print_error("exit", " numeric argument required", 255);
		exit(255);
	}
	if (c[2] && ft_isdigit(c[1]))
	{
		printf("exit\n");
		print_error("exit", " too many arguments", 1);
		return (0);
	}
	str = ft_cat_str(c[1]);
	exit_2(str);
	return (0);
}

void	exit_2(char *str)
{
	long long	num;

	num = 0;
	if (check_longlongd(str))
	{
		num = ft_atoi(str);
		if (num < 0)
		{
			ft_putstr_fd("exit\n", 2);
			exit(256 - (num * (-1) % 256));
		}
		else if (num >= 0)
		{
			ft_putstr_fd("exit\n", 2);
			exit(num % 256);
			g_exit_code = num % 256;
		}
	}
	else
	{
		print_error("exit", "numeric argument required", 255);
		exit(255);
	}
	free(str);
}
