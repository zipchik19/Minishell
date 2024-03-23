/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 10:38:51 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/23 10:50:36 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# define MSG "syntax error near unexpected token `newline'"

extern int				g_exit_code;

typedef struct s_count
{
	int	count_herdoc;
	int	count_1;
	int	count_3;
	int	count_4;
}	t_count;

typedef struct s_redirs
{
	int					flag;
	char				*pathname;
	char				*del;
	struct s_redirs		*next;
}	t_redirs;

typedef struct s_toks	t_toks;

struct s_toks
{
	char		*rdl;
	char		**cmd;
	int			*hrd_count;
	int			token_count;
	int			in_copy;
	int			out_copy;
	t_redirs	*head_redct;
	t_toks		*next;
};

typedef struct s_env	t_env;

struct s_env
{
	char	*key;
	char	*value;
	int		flag;
	t_env	*next;
};

char				*ft_itoa(int n);
long long			ft_atoi(const char *str);
int					ft_int_strchr(char *str, char c);
char				*ft_strchr(char *str, int c);
char				**split_export(char *str);
char				*ft_strdup( char *s1);
void				free_envs(char **env_split);
int					ft_strcmp1(char *s1, char *s2);
int					ft_strcmp(char *str, char *cmd);
char				*ft_strtrim(char *s1, char *set);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strjoin1(char *s1, char *s2);
char				**ft_split(char const *s, char c);
char				*ft_substr(char *s, int start, int len);
char				**smart_split(char *s, char c);
char				*ft_cat_str(char *s);
int					ft_isdigit(char *str);
void				ft_putstr_fd(char *s, int fd);
//////////////////////char				*ignore_quotes(char *str);
void				*ft_calloc(int c, int s);
int					ft_strlen(char *str);
int					ft_strcrcmp(char *str, char c);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				ft_putstr_fd_endl(char *s, int fd, int fl);

void				env_cmd(t_env *env);
void				echo_cmd(char **str);
int					echo_cmd_1(char *str, int *flag);
void				echo_cmd_2(char **str, int i);
void				echo_cmd_2(char **str, int i);
void				echo_cmd_3(char **str, int i);
void				pwd_cmd(t_env **t_env);
void				only_export(t_env **node);
void				export_no_args(t_env **env);
void				cd_cmd(t_env **l_env, char **str);
void				unset_cmd(t_env **l_env, char *new_key, char *cmd);

void				execve_cmd(t_env **env, char **str);
void				execve_cmd2(t_env **env, char **str);
int					exit_cmd(char **c);
void				exit_2(char *str);
int					check_longlongd(char *str);
int					check_longlongd1(char *str);
int					check_longlongd2(char *str);
int					check_longlongd3(char *str);

void				redirection_output(char *file, int i);
void				redirection_output_append(char *file, int i);
void				redirection_input(char *file, int i);
void				heredoc(char *key, int i);
void				heredoc_part2(int i, int fd, char *file);
int					status_check(char *file, char *s);

int					sp_trim(char *str);
int					main_pars(t_toks **token, t_env **env, char **str);
void				parsing_part_1(char *str, t_toks **token);
char				*dolars_join(char *str, char *world, int x, int z);
int					exp_pars(char *str, char *val, char *cmd);
int					pre_parsing(char *str);
int					syntax_pars_2(char *str);
int					syntax_pars_3(char *str);
void				dolar_pars(char **str);
void				dollar_harcakan(void);
int					skip_find_sp_idx(char *str, int i);

void				ft_signal_handling(int sig);
void				handleterm(int s);
void				handle_ctrl_d(int sig);
void				sig_handler_hdoc(int sig);
void				sigint_handler(int sig);
void				handler(int sig);
void				ctrl_d_check(char *s);
void				sig_control(int a);

t_env				*ft_lstlast(t_env *lst);
void				ft_lstadd_back(t_env **lst, t_env *new);
t_redirs			*new_redirs(int flag, char *del, char *pathname);
void				redirs_add_back(t_redirs **head, t_redirs *new_node);
t_redirs			*new_redirs(int flag, char *del, char *pathname);
void				redirs_add_back(t_redirs **head, t_redirs *new_node);
void				free_toks(t_toks **token);
void				free_node(t_env **rtv);
t_toks				*new_toks(char *rdl, char **cmd, int *hrd_count, \
					int count_token);

int					env_len(t_env **l_env);
void				env_init(char **env, t_env **s_env);
void				shell_level(t_env **env);
int					find_key(t_env **l_env, char *new_key);
int					if_key_already_exist(t_env **l_env, char **splited);
void				already_exist(char **splited, t_env *rtv);
void				need_to_add(t_env **l_env, char **splited, t_env *rtv, \
					char *tmp);
int					if_need_to_add(t_env **l_env, char **splited);
t_env				*get_env(t_env **l_env, char *new_key);
void				initializer(t_toks **token);
void				dolar_harc(char **str);
void				tokenization(t_toks **token, char **str );
int					matrix_len(char **str);
int					error_msgs(char **tokenized, char *str);
void				tf_norm(t_toks **token);
void				fill_reds(t_toks **token, int flag, char *str);
t_toks				*ft_lstlast1(t_toks *lst);

t_count				*count_all(t_toks **tk);
t_count				*count_red(t_toks **tk);
t_count				*count_redirect(t_toks **tk);
int					tok_count(char **token);
int					pipe_count(char *str);

void				running_pipe(t_toks **token, t_env **env);
void				ft_pipe_call(int (*fd)[2], int count);
void				func_red(t_toks **token);
void				call_heredoc(t_toks **tk, int len);
void				run_p(pid_t *child, t_toks **token, t_env **env, \
					int (*fd)[2]);
void				running_p(t_toks **tk, t_env **l_env, int (*fd)[2], int i);
void				running_p(t_toks **token, t_env **l_env, int (*fd)[2], \
					int i);
void				child_pr(int (*fd)[2], int i, int count);
void				call_redirections6(t_toks **tk, t_count *len);
void				running_p_part1(t_toks *token, t_env **l_env, t_env *env);
void				fd_close(int (*fd)[2], int count);
void				processing_status_pipe( pid_t *a, int size);

void				running(t_toks **token, t_env **l_env);
void				call_redirections(t_toks **tk);
void				processing_status(int size);

int					check(int i, char *str, int *flg);
int					back_check(char *str, int x);
int					front_check(char *str, int *x);
int					check_cmd( t_toks **token, int i);
int					check_herdoc( t_toks **token, int i);
int					check_redirect( t_toks **token, int i);

void				print_error(char *cmd, char *str, int code);
int					execve_print(char *str, int z);
void				child_error(int i, pid_t *child);

int					end_of_2quote(char *str, int i);
int					end_of_1quote(char *str, int i);

void				ft_execv(char *new_str, char **mx_env, char **str);
char				*cheack_access(char **path, char **str, char **mx_env);
char				**t_env_to_matrix(t_env **env);
void				create_the_paths(char **splited_path, char *new_str);
int					quotes_pars(char *str);

int					ft_strcmp_part2(char *str, char *cmd, int len);
char				**smart_split1(char *s, char c);
void				other_smart_split(t_toks **token);
int					smart_split_part1(int start, char *s, char c, int i);
int					smart_split_part2(int end, char *s, char c );
void				sub_sub(char *rdl, t_toks **hert);
int					sub_sub_part1(char *rdl, int i, t_toks **hert);
int					sub_sub_part2(char *rdl, int i, t_toks **hert);
int					sub_sub_part3(char *rdl, int i, t_toks **hert);
int					sub_sub_part4(char *rdl, int i, t_toks **hert);
int					sub_sub_part5(char *rdl, int i, char	**tmp);
void				do_the_job(t_redirs *token, t_count *len);
void				print_error_exit(char *cmd, char *val, char *str, int code);
unsigned long long	ft_atoi2(const char *str);
void				export_cmd(t_env **l_env, char *str, char *cmd);
void				running_part1(t_toks *token, t_env **l_env, t_env *env);
char* 				ignore_quotes(char* str);

#endif
