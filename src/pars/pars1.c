#include "../../minishell.h"

int	pars11(char c)
{
	if (c == '|' || c == '&' || c == ';')
	{
		g_exit_code = 2;
		error_msg(NULL, "syntax error ", 258);
		return (1);
	}
	return (0);
}

int	pars12(char *str)
{
	int	i;
	int	flag;
	int	len;

	len = ft_strlen(str);
	flag = 1;
	i = 0;
	while (str[i])
	{
		i = check(i, str, &flag);
		if (!flag)
			break ;
		if (str[i] && str[i] != '>' && str[i] != '<')
			i++;
	}
	if (flag == 0)
	{
		error_msg(NULL, "syntax error ", 258);
		return (1);
	}
	return (0);
}

int	pars13(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			i = chakerts_end(str, i);
		else if (str[i] == '\"')
			i = double_chakerts_end(str, i);
		if (str[i] == '|' && str[i + 1])
		{
			i++;
			while (str[i] == ' ')
				i++;
			if (str[i] == '|')
			{
				error_msg(NULL, "syntax error ", 258);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int parses(char **str)
{
    if (pars11(*str[0]))
        return (1);
    if (pars12(*str))
        return (1);
    if (pars13(*str))
        return (1);
    return (0);    
}

int	pars1(t_tokens **token, t_env **env, char **str)
{
	t_tokens	*tok;
	char		*tmp;

	(void)env;
	tok = *token;
	tmp = *str;
	*str = ft_strtrim(tmp, " ");
	free(tmp);
	if (parses(str))
		return (1);
	dollar(str);
	dollar_harc(str);
	//tokenization
	return (0);
}