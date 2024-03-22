#include "../../minishell.h"

int check_nums(char *c)
{
	long long nb;
	
	nb = ft_atoi2(c);
	if(ft_strcmp(c, "-9223372036854775808"))
		return(1);
	if(ft_strlen(c) <= 19)
	{
		if(nb < 0)
			nb = -1 * ft_atoi(c);
		if (nb >=0 && nb <= 9223372036854775807)
			return(1);
		return(0);
	}
	return(0);
}


int	exit_cmd(char **c)
{
	char		*str;
	unsigned long long nb;

	if (!c[1])
	{
		printf("exit\n");
		exit(0);
	}
	if(ft_atoi(c[1]) < 0)
		nb = -1 * ft_atoi(c[1]);
	nb = ft_atoi(c[1]);
	printf("%d\n", check_nums("9223372036854775807135813514351"));
	if (!ft_isdigit(c[1]) || (c[2] && !ft_isdigit(c[1])) || (!check_nums(c[1])))
	{
		printf("exit\n");
		print_error_exit("exit", c[1], "numeric argument required", 255);
		exit(255);
	}
	if (c[2] && ft_isdigit(c[1]))
	{
		printf("exit\n");
		print_error("exit", "too many arguments", 1);
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
		printf("exit\n");
		print_error_exit("exit", str, "numeric argument required", 255);
		exit(255);
	}
	free(str);
}
