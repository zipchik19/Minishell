#include "../../minishell.h"

int	front_check(char *str, int *t)
{
	int	i;

	while (str[*t] && str[*t] == ' ')
			(*t)++;
	i = *t;
	while (str[*t] && !ft_strchr(METACHARS, str[*t]))
		(*t)++;
	if (*t - i <= 0)
		return (1);
	return (0);
}

int	back_check(char *str, int t)
{
	int	i;

	if (t == 0)
		return (1);
	while (str[t] && str[t] == ' ')
			t--;
	i = t;
	while (!ft_strchr(METACHARS, str[t]) && str[i])
		t--;
	if (i - t <= 0)
		return (1);
	return (0);
}
