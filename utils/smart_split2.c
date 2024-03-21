#include "../../minishell.h"

int	smart_split_part2(int end, char *s, char c )
{
	while (s[end] && s[end] != c)
	{
		if (s[end] && s[end] == '\"')
			end = find_end_of_double_quote(s, end);
		if (s[end] && s[end] == '\'')
			end = find_end_of_single_quote(s, end);
		end++;
	}
	return (end);
}

int	smart_split_part1(int start, char *s, char c, int i)
{
	while (s[start] && s[start] == c)
	{
		if (s[start] && s[start] == '\"')
			start = find_end_of_double_quote(s, i);
		if (s[start] && s[start] == '\'')
			start = find_end_of_single_quote(s, i);
			start++;
	}
	return (start);
}
