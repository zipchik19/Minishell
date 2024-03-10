#include "../../minishell.h"

int chakerts_end(char *str, int i)
{
	i++;
	while (str[i] && str[i] != '\'' )
		i++;
	return (i);
}

int double_chakerts_end(char *str, int i)
{	
	i++;
	while (str[i] && str[i] != '\"')
		i++;
	return (i);
}