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

char	*ignore_chak2(char *str, int i, int j)
{
	char	*tmp;

	tmp = NULL;
	tmp = malloc(sizeof(char *) * (i - j + 1));
	tmp[i - j] = 0;
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != '\'' && str[i] != '\"')
		{
			tmp[j] = str[i];
			j++;
		}
		i++;
	}
	free (str);
	return (tmp);
}

char	*ignore_chak(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			j++;
		i++;
	}
	return (ignore_chak2(str, i, j));
}