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

typedef struct s_chakerts	t_chakerts;

struct	s_chakerts
{
	int					flag;
	char				*path;
	char				*del;
	struct s_chakerts	*next;
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

t_chakerts	*new_chakerts(int flag, char *del, char *pathname);
t_tokens	*ft_lstlastt(t_tokens *lst);
t_env	*get_env(t_env **l_env, char *new_key);
void	sig_control(int a);
void	init_env(char **env, t_env **cur_env);
void	lvlshell(t_env **env);
void	ctrl_d(char *str);
int		trim_sp(char *str);
int		pars1(t_tokens **token, t_env **env, char **str);
int		chakerts_end(char *str, int i);
int		double_chakerts_end(char *str, int i);
void    error_msg(char *cmd, char *str, int numb);
int		check(int i, char *str, int *flag);
void	dollar(char **str);
void	dollar_harc(char **str);
void	*str_free(char **str, size_t i);
int		table_len(char **str);
int		check_error(char **tokenized, char *str);
char	**new_split(char *str, char c);
int		sub1(char *line, int i, t_tokens **queue);
int		sub2(char *line, int i, t_tokens **queue);
int		sub3(char *line, int i, t_tokens **queue);
int		sub4(char *line, int i, t_tokens **queue);
int		sub5(char *line, int i, char	**tmp);
char	*ignore_chak(char *str);
void	chakerts_add_back(t_chakerts **head, t_chakerts *new_node);
void	ignoring(t_tokens **token);
void	very_new_split(t_tokens **token);
t_tokens	*new_tokens(char *rdl, char **cmd, int *hrd_count, int count_token);
void	fill_chakerts(t_tokens **token, int flag, char *str);
// void	fill_tokens(t_tokens **token, char **tokenized, int *hrd_c, int count_tok);
//utils
int	till_spaces(char *str, int i);
void	chakerts_add_back(t_chakerts **head, t_chakerts *new_node);


//libft utils
char	**ft_split(char *s, char c);
int		ft_strlen(char *str);
int		ft_strcmp(char *str, char *cmd);
int		ft_strcmp1(char *s1, char *s2);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
char	*ft_strtrim(char *s1, char *set);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int start, int len);
int		ft_strcharcmp(char *str, char c);
char	*ft_strjoin2(char *s1, char *s2);

#endif