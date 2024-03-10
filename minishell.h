#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h> 
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <string.h>
# include <termios.h>
# include <sys/ioctl.h>

# define METACHARS " |&()<>;"
# define METAE	"=-.!@#$^&*()}{"
# define REDE	"<> " 


extern int					g_exit_code;

typedef struct s_count		t_count;

struct	s_count
{
	int	count_herdoc;
	int	count_1;
	int	count_3;
	int	count_4;
};

typedef struct s_redirects	t_chakerts;

struct	s_chakerts
{
	int					flag;
	char				*path;
	char				*del;
	struct t_chakerts	*next;
};

typedef struct s_tokens		t_tokens;

struct s_tokens
{
	char		*rdl;
	char		**cmd;
	int			*hrd_count;
	int			token_count;
	int			in_cpy;
	int			out_cpy;
	t_chakerts	*head_redct;
	t_tokens	*next;
};

typedef struct s_env		t_env;

struct	s_env
{
	char	*key;
	char	*value;
	int		flag;
	t_env	*next;
};

void	sig_control(int a);
t_env	*get_env(t_env **l_env, char *new_key);
void	init_env(char **env, t_env **cur_env);
void	lvlshell(t_env **env);
void	ctrl_d(char *str);
int		trim_sp(char *str);
int		pars1(t_tokens **token, t_env **env, char **str);
int		chakerts_end(char *str, int i);
int		double_chakerts_end(char *str, int i);
void    error_msg(char *cmd, char *str, int numb);
int		check(int i, char *str, int *flag);





//libft utils
char	**ft_split(char *s, char c);
int		ft_strlen(char *str);
int		ft_strcmp(char *str, char *cmd);
int		ft_strcmp1(char *s1, char *s2);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
char	*ft_strtrim(char *s1, char *set);
char	*ft_strchr(const char *s, int c);

#endif