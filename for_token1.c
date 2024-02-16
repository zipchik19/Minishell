#include "minishel.h"

t_token *new_token(int type, char*str)
{
    t_token *token;

    token = malloc(sizeof(t_token));
    if(!token)
        return (0);
    t_token->value = ft_strdup(str);
    free(str);
    t_token->type = type;
    t_token->prev = NULL;
    t_token->next = NULL;

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
		error("shyshell: \': Token error", 1);//////////////create the error func
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
    t_token	*new;

	ban = (*str);
    if (*str[0] == '>')
    {
        (*str)++;
        ban = ft_strdup(">>");  
	    return (new_tok(MEC2, ban));
    }
    else
    {
        ban = ft_strdup('>');
	    return (new_tok(MEC, ban));
    }
//////////////create the error func
	return (0);
}

t_token *poqr_tok(char **str)
{
    char	*ban;
    t_token	*new;

	ban = (*str);
    if (*str[0] == '<')
    {
        (*str)++;
        ban = ft_strdup("<<");  
	    return (new_tok(POQR2, ban));
    }
    else
    {
        ban = ft_strdup('<');
	    return (new_tok(POQR, ban));
    }
//////////////create the error func
	return (0);
}


_token	*pipe_tok(char **str)
{
	char	*ban;

	(*str)++;
	ban = ft_strdup("|");
	return (new_token(PIPE, ban, 0));
}






/////////NORM ERROR