#ifndef MINISHELL_H
# define MINISHELL_H

# define SP 1 // spaces // dont need validation
# define WORD 2 // words // partly done
# define FIELD 3 // '  ' // dont need vslidation
# define EXP_FIELD 4 // " " // not done
# define REDIR_OUT 5 // >
# define PIPE 6 // |
# define REDIR_IN 7 // <
# define REDIR_AP 8 // >>
# define REDIR_SO 9 // <<
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


typedef struct s_token
{
	int		type;
	char	*value;
	int		in;///////////////
	int		out;///////////////
	int		op;/////////////////
	t_token	*prev;
	t_token	*next;
} t_token;










#endif