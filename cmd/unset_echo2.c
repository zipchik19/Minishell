#include "../../minishell.h"

int	echo_cmd_1(char *str, int *flag)
{
	int	i;

	i = 0;
	i++;
	while (str[i])
	{
		if (str[i] == 'n')
			i++;
		else
		{
			*flag = 1;
			break ;
		}	
		if (i != 2)
			*flag = 0;
	}
	return (i);
}

void	echo_cmd_2(char **str, int i)
{
	i = 0;
	if (str[2])
	{
		i = 2;
		while (ft_strcmp(str[i], "-n"))
			i++;
		while (str[i] && str[i + 1])
		{
			printf("%s", str[i]);
				i++;
		}
		printf("%s", str[i]);
	}
}

void	echo_cmd_3(char **str, int i)
{
	if (str[1])
	{
		i = 1;
		while (str[i] && str[i + 1])
		{
			printf("%s", str[i]);
			i++;
		}
		printf("%s", str[i]);
		printf("\n");
	}
	else
		printf("\n");
}
