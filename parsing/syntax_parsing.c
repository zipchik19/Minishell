#include "../../minishell.h"

int	syntax_pars_2(char *str)
{
	int	i;
	int	flg;
	int	len;

	len = ft_strlen(str);
	flg = 1;
	i = 0;
	while (str[i])
	{
		i = check(i, str, &flg);
		if (!flg)
			break ;
		if (str[i] && str[i] != '>' && str[i] != '<')
				i++;
	}
	if (flg == 0)
	{
		print_error(NULL, "syntax error near unexpected token `newline", 258);
		return (1);
	}
	return (0);
}

int	syntax_pars_3(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			i = end_of_1quote(str, i);
		else if (str[i] == '\"')
			i = end_of_2quote(str, i);
		if (str[i] == '|' && str[i + 1])
		{
			i++;
			while (str[i] == ' ')
				i++;
			if (str[i] == '|')
			{
				print_error(NULL, "syntax error nearunexpected token `newline",
					258);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int	syntax_pars_1(char c)
{
	if (c == '|' || c == '&' || c == ';')
	{
		g_exit_code = 2;
		print_error(NULL, "syntax error near unexpected token `newline", 258);
		return (1);
	}
	return (0);
}

int	syntax_pars(char **str)
{
	if (syntax_pars_1(*str[0]))
		return (1);
	if (syntax_pars_2(*str))
		return (1);
	if (syntax_pars_3(*str))
		return (1);
	return (0);
}

int	main_pars(t_toks **tok, t_env **env, char **str)
{
	t_toks		*tk;
	char		*tmp;

	(void)env;
	tk = *tok;
	tmp = *str;
	*str = ft_strtrim(tmp, " ");
	free(tmp);
	if (syntax_pars(str))
		return (1);
	dolar_pars(str);
	dolar_harc(str);
	tokenization(tok, str);
	return (0);
}
