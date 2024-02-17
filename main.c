#include "minishell.h"

void printList(t_token* head)
{
    while (head != NULL)
    {
        printf("%s", head->value);
        head = head->next;
    }
    printf("\n");
}

//////////////here we tokenizing the input and printing the tokens sseperately/////////readline issues
int main(int ac, char **av)
{
    char **str;
    t_token *list = NULL;

    (void)ac;
    str = av;
    
    for (int i = 1; str[i]; i++)
    {
        list = NULL;
        tokenize(&list, str[i]);
        printList(list);
    }
    return 0;
}
