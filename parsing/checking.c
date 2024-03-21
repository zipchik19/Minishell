#include "../../minishell.h"

int	front_check(char *str, int *x)
{
	int	i;

	while (str[*x] && str[*x] == ' ')
			(*x)++;
	i = *x;
	while (str[*x] && !ft_strchr(METACHARS, str[*x]))
		(*x)++;
	if (*x - i <= 0)
		return (1);
	return (0);
}

int	back_check(char *str, int x)
{
	int	i;

	if (x == 0)
		return (1);
	while (str[x] && str[x] == ' ')
			x--;
	i = x;
	while (!ft_strchr(METACHARS, str[x]) && str[i])
		x--;
	if (i - x <= 0)
		return (1);
	return (0);
}
