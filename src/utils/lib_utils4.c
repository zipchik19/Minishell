#include "../../minishell.h"

int	find_in_set(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char *s1, char *set)
{
	int		i;
	int		start;
	int		end;
	char	*str;

	i = 0;
	start = 0;
	while (s1[i])
		i++;
	end = i;
	i = 0;
	while (s1[start] && find_in_set(s1[start], set))
		start++;
	while (start < end && find_in_set(s1[end - 1], set))
		end--;
	str = malloc(end - start + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (start < end && s1[start])
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	a;

	a = (char)c;
	i = 0;
	while (s[i] || a == 0)
	{
		if (s[i] == a)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}