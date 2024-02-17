#include "minishell.h"

t_token *new_tok(int type, char*str)
{
    t_token *token;

    token = malloc(sizeof(t_token));
    if(!token)
        return (0);
    token->value = ft_strdup(str);
    free(str);
    token->type = type;
    token->prev = NULL;
    token->next = NULL;

    return(token);
}

t_token *space_tok(char **str)
{
    t_token *new;
    char    *ban;

    ban = *str;
    while (*str[0] == ' ' && *str)
        (*str)++;
    ban = ft_substr(ban, 0, *str - ban);
    new = new_tok(SP, ban);/////////////////
    return (new);
}

t_token *word_tok(char **str)
{
    t_token *new;
    char    *ban;

    ban = *str;
    while (*str && ft_isprint(*str[0]) && *str[0] != '<' \
            && *str[0] != '>' && *str[0] != '|' && *str[0] != 39 \
            && *str[0] != 34) 
        (*str)++;
    ban = ft_substr(ban, 0, *str - ban);
    new = new_tok(WORD, ban);/////////////////
    return (new);
}

t_token *chakert_tok(char **str)
{
    char	*ban;
	t_token	*new;

	ban = (*str);
	(*str) = ft_strchr(++ban, 39);
	if (!(*str))
	{
		//error("shyshell: \': Token error", 1);//////////////create the error func
		return (NULL);
	}
	ban = ft_substr(ban, 0, (*str) - ban);
	(*str)++;
	new = new_tok(CHAK, ban);//////////
	return (new);
}

t_token *chakert2_tok(char **str)
{
   char	*ban;
   t_token	*new;

	ban = (*str);
	(*str) = ft_strchr(++ban, 34);
	if (!(*str))
	{
		//////////////create the error func
		return (NULL);
	}
	ban = ft_substr(ban, 0, (*str) - ban);
	(*str)++;
	new = new_tok(CHAK2, ban);//////////
	return (new);
}


t_token *mec_tok(char **str)
{
    char	*ban;
    //t_token	*new;

	ban = (*str);
    if (*str[0] == '>')
    {
        (*str)++;
        ban = ft_strdup(">>");  
	    return (new_tok(MEC2, ban));
    }
    else
    {
        ban = ft_strdup(">");
	    return (new_tok(MEC, ban));
    }
//////////////create the error func
	return (0);
}

t_token *poqr_tok(char **str)
{
    char	*ban;
    //t_token	*new;

	ban = (*str);
    if (*str[0] == '<')
    {
        (*str)++;
        ban = ft_strdup("<<");  
	    return (new_tok(POQR2, ban));
    }
    else
    {
        ban = ft_strdup("<");
	    return (new_tok(POQR, ban));
    }
//////////////create the error func
	return (0);
}


t_token	*pipe_tok(char **str)
{
	char	*ban;

	(*str)++;
	ban = ft_strdup("|");
	return (new_tok(PIPE, ban));
}


t_token	*token_type(char **str)
{
	t_token	*token;

	token = NULL;
	if (*str[0] == '|')
		token = pipe_tok(str);
	else if (*str[0] == 39)
		token = chakert_tok(str);
	else if (*str[0] == '>')
		token = mec_tok(str);
	else if (*str[0] == '<')
		token = poqr_tok(str);
	else if (*str[0] == 34)
		token = chakert_tok(str);
	else if (ft_isprint(*str[0]))
		token = word_tok(str);
	else if (*str[0] == ' ')
		token = space_tok(str);
	return (token);
}

int	tokenize(t_token **stream, char *str)
{
	t_token	*tmp;

	tmp = NULL;
	while (*str)
	{
		(*stream) = token_type(&str);
		// if (!(*stream))
		// {
		// 	if (g_exit_statuss != 1)
		// 		g_exit_statuss = 0;
		// 	else
		// 		return (1);
		// 	break ;
		// }
		(*stream)->prev = tmp;
		tmp = (*stream);
		stream = &(*stream)->next;
    }
	return (0);
}


/////////NORM ERROR