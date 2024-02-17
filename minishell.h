#ifndef MINISHELL_H
# define MINISHELL_H

# define SP 1 // spaces // dont need validation
# define WORD 2 // words // partly done
# define CHAK 3 // '  ' // dont need vslidation
# define CHAK2 4 // " " // not done
# define MEC 5 // >
# define POQR 6 // <
# define PIPE 7 // |
# define MEC2 8 // >>
# define POQR2 9 // <<
# define STDOUT 1
# define STDIN 0

# include <sys/stat.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <./readline/readline.h>
# include <readline/history.h>
# include "./libft/libft.h"
# include <dirent.h>

typedef struct s_token t_token;

struct s_token
{
	int		type;
	char	*value;
	int		in;///////////////
	int		out;///////////////
	int		op;/////////////////
	t_token	*prev;
	t_token	*next;
};


int	tokenize(t_token **stream, char *str);
void printList(t_token* head);

#endif