#include "../../minishell.h"

int	check_part2(int i, char *str, int **flg)
{	
	if (!str[i + 1])
	{
		**flg = 0;
	}
	else if (str[i + 1] && str[i + 1] != '>')
	{
		i++;
		if (cheack_front(str, &i))
		**flg = 0;
	}
	else if (str[i + 1] && str[i + 1] == '>')
	{
		i += 2;
		if (cheack_front(str, &i))
		**flg = 0;
	}
	return (i);
}

int	check_part1(int i, char *str, int **flg)
{
	if (!str[i + 1])
		**flg = 0;
	else if (str[i + 1] && str[i + 1] != '<')
	{
		i++;
		if (cheack_back(str, i - 1) || cheack_front(str, &i))
			**flg = 0;
	}
	else if (str[i + 1] && str[i + 1] == '<')
	{
		i += 2;
		if (cheack_front(str, &i))
			**flg = 0;
	}
	return (i);
}

int	check(int i, char *str, int *flg)
{
	if (str[i] == '\'')
		i = find_end_of_single_quote(str, i);
	else if (str[i] == '\"')
		i = find_end_of_double_quote(str, i);
	else if (str[i] && str[i] == '<')
	{	
		i = check_part1(i, str, &flg);
	}
	else if (str[i] && str[i] == '>')
	{
		i = check_part2(i, str, &flg);
	}
	return (i);
}
