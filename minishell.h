#ifndef MINISHELL_H
# define MINISHELL_H

# include "utils.h"
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

typedef struct s_redirects	t_redirects;

struct	s_redirects
{
	int					flag;
	char				*pathname;
	char				*del;
	struct s_redirects	*next;
};

typedef struct s_tokens		t_tokens;

struct s_tokens
{
	char		*rdl;
	char		**cmd;
	int			*hrd_count;
	int			token_count;
	int			in_copy;
	int			out_copy;
	t_redirects	*head_redct;
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

void		env_cmd(t_env *env);
void		echo_cmd(char **str);
int			echo_cmd_1(char *str, int *flag);
void		echo_cmd_2(char **str, int i);
void		echo_cmd_2(char **str, int i);
void		echo_cmd_3(char **str, int i);
void		pwd_cmd(t_env **t_env);
void		only_export(t_env **node);
void		export_no_args(t_env **env);
void		cd_cmd(t_env **l_env, char **str);
void		unset_cmd(t_env **l_env, char *key);
void		export_cmd(t_env **l_env, char *str);
void		execve_cmd(t_env **env, char **str);
void		execve_cmd2(t_env **env, char **str);
int			exit_cmd(char **c);
void		exit_2(char *str);
int			check_longlongd(char *str);
int			check_longlongd1(char *str);
int			check_longlongd2(char *str);
int			check_longlongd3(char *str);

void		redirection_output(char *file, int i);
void		redirection_output_append(char *file, int i);
void		redirection_input(char *file, int i);
void		heredoc(char *key, int i);
void		heredoc_part2(int i, int fd, char *file);
int			status_check(char *file, char *s);

int			sp_sp(char *str);
int			gen_parsing(t_tokens **token, t_env **env, char **str);
void		parsing_part_1(char *str, t_tokens **token);
char		*join_dolar_str(char *str, char *world, int x, int z);
int			export_pars(char *str);
int			pre_parsing(char *str);
int			syntax_pars_2(char *str);
int			syntax_pars_3(char *str);
void		dolar_pars(char **str);
void		dollar_harcakan(void);
int			go_until_spasce(char *str, int i);
char		*join_dolar_str(char *str, char *world, int x, int z);

void		ft_signal_handling(int sig);
void		handleterm(int s);
void		handle_ctrl_d(int sig);
void		sig_handler_hdoc(int sig);
void		sigint_handler(int sig);
void		handler(int sig);
void		ctrl_d_check(char *s);
void		sig_control(int a);

t_env		*ft_lstlast(t_env *lst);
void		ft_lstadd_back(t_env **lst, t_env *new);
t_redirects	*new_t_redirects(int flag, char *del, char *pathname);
void		t_redirects_add_back(t_redirects **head, t_redirects *new_node);
t_redirects	*new_t_redirects(int flag, char *del, char *pathname);
void		t_redirects_add_back(t_redirects **head, t_redirects *new_node);
void		free_t_list(t_tokens **token);
void		one_node_free(t_env **rtv);
t_tokens	*new_t_tokens(char *rdl, char **cmd,
				int *hrd_count, int count_token);

int			env_len(t_env **l_env);
void		env_init(char **env, t_env **s_env);
void		shell_level(t_env **env);
int			find_key(t_env **l_env, char *new_key);
int			if_key_already_exist(t_env **l_env, char **splited);
void		already_exist(char **splited, t_env *rtv);
void		need_to_add(t_env **l_env, char **splited, t_env *rtv, char *tmp);
int			if_need_to_add(t_env **l_env, char **splited);
t_env		*get_env(t_env **l_env, char *new_key);
void		initializer(t_tokens **token);
void		interrogatory(char **str);
void		tokenization(t_tokens **token, char **str );
int			matrix_len(char **str);
int			check_error(char **tokenized, char *str);
void		ftft(t_tokens **token);
void		ft_fill_red(t_tokens **token, int flag, char *str);
t_tokens	*ft_lstlast1(t_tokens *lst);

t_count		*count_all(t_tokens **tk);
t_count		*count_red(t_tokens **tk);
t_count		*count_redirect(t_tokens **tk);
int			ft_count_tokens(char **token);
int			ft_count_pipe(char *str);

void		running_pipe(t_tokens **token, t_env **env);
void		ft_pipe_call(int (*fd)[2], int count);
void		func_red(t_tokens **token);
void		call_heredoc(t_tokens **tk, int len);
void		run_p(pid_t *child, t_tokens **token, t_env **env, int (*fd)[2]);
void		running_p(t_tokens **tk, t_env **l_env, int (*fd)[2], int i);
void		running_p(t_tokens **token, t_env **l_env, int (*fd)[2], int i);
void		child_pr(int (*fd)[2], int i, int count);
void		call_redirections6(t_tokens **tk, t_count *len);
void		running_p_part1(t_tokens *token, t_env **l_env, t_env *env);
void		fd_close(int (*fd)[2], int count);
void		processing_status_pipe( pid_t *a, int size);

void		running(t_tokens **token, t_env **l_env);
void		call_redirections(t_tokens **tk);
void		processing_status(int size);

int			check(int i, char *str, int *flg);
int			cheack_back(char *str, int x);
int			cheack_front(char *str, int *x);
int			check_cmd( t_tokens **token, int i);
int			check_herdoc( t_tokens **token, int i);
int			check_redirect( t_tokens **token, int i);

void		print_error(char *cmd, char *str, int code);
int			execve_print(char *str, int z);
void		child_error(int i, pid_t *child);

int			find_end_of_double_quote(char *str, int i);
int			find_end_of_single_quote(char *str, int i);

void		ft_execv(char *new_str, char **mx_env, char **str);
char		*cheack_access(char **path, char **str, char **mx_env);
char		**t_env_to_matrix(t_env **env);
void		create_the_paths(char **splited_path, char *new_str);

int			ft_strcmp_part2(char *str, char *cmd, int len);
char		**smart_split1(char *s, char c);
void		smart_smart_split(t_tokens **token);
int			smart_split_part1(int start, char *s, char c, int i);
int			smart_split_part2(int end, char *s, char c );
void		ft_smart_sub(char *rdl, t_tokens **hert);
int			ft_smart_sub_part1(char *rdl, int i, t_tokens **hert);
int			ft_smart_sub_part2(char *rdl, int i, t_tokens **hert);
int			ft_smart_sub_part3(char *rdl, int i, t_tokens **hert);
int			ft_smart_sub_part4(char *rdl, int i, t_tokens **hert);
int			ft_smart_sub_part5(char *rdl, int i, char	**tmp);
void		do_the_job(t_redirects *token, t_count *len);

#endif