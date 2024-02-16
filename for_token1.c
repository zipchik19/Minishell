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