#include "../../minishell.h"

int	till_spaces(char *str, int i)
{
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] && str[i] != ' ')
		i++;
	return (i);
}