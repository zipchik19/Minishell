#include "../../minishell.h"

int	smart_split_part2(int end, char *s, char c )
{
	while (s[end] && s[end] != c)
	{
		if (s[end] && s[end] == '\"')
			end = end_of_2quote(s, end);
		if (s[end] && s[end] == '\'')
			end = end_of_1quote(s, end);
		end++;
	}
	return (end);
}

int	smart_split_part1(int start, char *s, char c, int i)
{
	while (s[start] && s[start] == c)
	{
		if (s[start] && s[start] == '\"')
			start = end_of_2quote(s, i);
		if (s[start] && s[start] == '\'')
			start = end_of_1quote(s, i);
			start++;
	}
	return (start);
}
