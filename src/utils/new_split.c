#include "../../minishell.h"

int	split2(int end, char *str, char c )
{
	while (str[end] && str[end] != c)
	{
		if (str[end] && str[end] == '\"')
			end = double_chakerts_end(str, end);
		if (str[end] && str[end] == '\'')
			end = chakerts_end(str, end);
		end++;
	}
	return (end);
}

int	split1(int start, char *str, char c, int i)
{
	while (str[start] && str[start] == c)
	{
		if (str[start] && str[start] == '\"')
			start = double_chakerts_end(str, i);
		if (str[start] && str[start] == '\'')
			start = chakerts_end(str, i);
			start++;
	}
	return (start);
}

static char	*word_fill(char *str, size_t start, size_t len)
{
	size_t	i;
	char	*word;

	i = 0;
	word = malloc(len + 1);
	if (word == 0)
		return (0);
	while (i < len)
	{
		word[i] = str[start + i];
		i++;
	}
	word[i] = 0;
	return (word);
}

static int	count_word(char *str, char delim)
{
	int	prev_del;
	int	i;
	int	count;

	i = 0;
	count = 0;
	prev_del = 1;
	while (str[i])
	{
		if (str[i] && str[i] == '\"')
			i = double_chakerts_end(str, i);
		if (str[i] && str[i] == '\'')
			i = chakerts_end(str, i);
		if (str[i] == delim)
			prev_del = 1;
		else if (prev_del)
			count++;
		if (str[i] != delim)
			prev_del = 0;
		i++;
	}
	return (count);
}

char	**new_split(char *str, char c)
{
	int		start;
	int		end;
	int		i;
	char	**line;

	i = -1;
	start = 0;
	line = malloc(sizeof (char *) * (count_word(str, c) + 1));
	if (line == 0)
		return (0);
	while (++i < count_word(str, c))
	{
		end = split1(start, str, c, i);
		start = end;
		end = split2(end, str, c);
		line[i] = word_fill(str, start, end - start);
		if (!line[i])
			str_free(line, i);
		start = end;
	}
	line[i] = 0;
	return (line);
}