#include "../../minishell.h"

t_env	*ft_lstlast(t_env *lst)
{
	if (lst == 0)
		return (0);
	while (lst -> next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_env **lst, t_env *new)
{
	t_env	*node;

	node = *lst;
	if (!node)
	{
		*lst = new;
		return ;
	}
	node = ft_lstlast(*lst);
	node->next = new;
}

char	*ft_strdup( char *s1)
{
	char	*s;
	int		l;

	l = ft_strlen(s1) + 1;
	s = (char *)malloc(l * sizeof(char));
	ft_memcpy (s, s1, l);
	return (s);
}
