/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:37:15 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/16 16:41:02 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h> 
# include <unistd.h>
# include <./readline/readline.h>
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
	int	count_hrd;
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
	int			table_count;
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
t_env		*get_env(t_env **l_env, char *new_key);
void		sig_control(int a);
void		init_env(char **env, t_env **cur_env);
void		lvlshell(t_env **env);
void		ctrl_d(char *str);
int			trim_sp(char *str);
int			pars1(t_tokens **token, t_env **env, char **str);
int			chakerts_end(char *str, int i);
int			double_chakerts_end(char *str, int i);
void		error_msg(char *cmd, char *str, int numb);
int			check(int i, char *str, int *flag);
void		dollar(char **str);
void		dollar_harc(char **str);
void		*str_free(char **str, size_t i);
int			table_len(char **str);
int			check_error(char **tokenized, char *str);
char		**new_split(char *str, char c);
int			sub1(char *line, int i, t_tokens **queue);
int			sub2(char *line, int i, t_tokens **queue);
int			sub3(char *line, int i, t_tokens **queue);
int			sub4(char *line, int i, t_tokens **queue);
int			sub5(char *line, int i, char	**tmp);
char		*ignore_chak(char *str);
void		chakerts_add_back(t_chakerts **head, t_chakerts *new_node);
void		ignoring(t_tokens **token);
void		very_new_split(t_tokens **token);
t_tokens	*new_tokens(char *rdl, char **cmd, int *hrd_count, int count_token);
void		fill_chakerts(t_tokens **token, int flag, char *str);
//utils
int			till_spaces(char *str, int i);
void		chakerts_add_back(t_chakerts **head, t_chakerts *new_node);
void		running_pipe(t_tokens **token, t_env **env);
void		func_red(t_tokens **token);
void		call_heredoc(t_tokens **tk, int len);
t_count		*count_all(t_tokens **tk);
void		pipe_call(int (*fd)[2], int count);
void		closee(int (*fd)[2], int count);
void		putstr_fd1(char *s, int fd, int fl);
void		run_p(pid_t *child, t_tokens **token, t_env **env, int (*fd)[2]);
void		processing_status_pipe(pid_t *a, int size);
void		exit2(char *str);
int			check_longlongd(char *str);
void		pwd_cmd(t_env **l_env);
void		env_cmd(t_env *env);
void		ft_putstr_fd(char *str, int fd);
void		heredoc(char *key, int i);
int			status_check(char *file, char *s);
void		running_p(t_tokens **token, t_env **l_env, int (*fd)[2], int i);
t_count		*count_redirect(t_tokens **tk);
void		child_pr(int (*fd)[2], int i, int count);
void		fd_close(int (*fd)[2], int count);
void		do_the_job(t_chakerts *token, t_count *len);
void		call_redirections6(t_tokens **tk, t_count *len);
void		redirection_input(char *file, int i);
void		redirection_output(char *file, int i);
void		only_export(t_env **node);
void		export_cmd(t_env **l_env, char *str);
void		cd_cmd(t_env **l_env, char **str);
void		echo_cmd(char **str);
void		unset_cmd(t_env **l_env, char *new_key);
void		execve_cmd2(t_env **env, char **str);
void		execve_cmd(t_env **env, char **str);
void		redirection_output_append(char *file, int i);
void		update_oldpwd(t_env **l_env);
void		ft_lstadd_back(t_env **lst, t_env *new);
char		*ft_strduplist( char *s1);
t_env		*ft_lstlast(t_env *lst);
void		update_pwd(t_env **l_env);
int			export_pars(char *str);
int			find_key(t_env **l_env, char *new_key);
int			echo_cmd_1(char *str, int *flag);
void		echo_cmd_2(char **str, int i);
void		echo_cmd_3(char **str, int i);
void		create_the_paths(char **splited_path, char *new_str);
char		**t_env_to_matrix(t_env **env);
char		*cheack_access(char **path, char **str, char **mx_env);
void		ft_execv(char *new_str, char **mx_env, char **str);
int			env_len(t_env **l_env);
char		**split_export(char *str);
int			if_key_already_exist(t_env **l_env, char **splited);
void		key_not_exist(char **splited, t_env *env, int i, int len);
void		export_print(char *str, int z);
int			if_need_to_add(t_env **l_env, char **splited);
void		already_exist(char **splited, t_env *rtv);
void		need_to_add(t_env **l_env, char **splited, t_env *rtv, char *tmp);
int			exit_cmd(char **c);
void		ft_execve_cmd_2(char **splited_path, char **str, \
			t_env **env, char *new_str);
void		signal_execve(void);
void		processing_status(int size);
void		call_redirections(t_tokens **tk);
int			call_redirections_part2(t_tokens **tk, t_count *len);
void		running_part1(t_tokens *token, t_env **l_env, t_env *env);
void		running(t_tokens **tk, t_env **l_env);
void		tokenization(t_tokens **token, char **str);
t_count		*count_red(t_tokens **tk);
int			count_redirect_part2(t_tokens *token, t_count **count);
void		free_part2(t_tokens **token);
void		free_t_list(t_tokens **token);
void		one_node_free(t_env **rtv);
void		matrix_free(char **env_split);
//libft utils
char		**ft_split(char *s, char c);
int			ft_strlen(char *str);
int			ft_strcmp(char *str, char *cmd);
int			ft_strcmp1(char *s1, char *s2);
int			ft_atoi(const char *str);
char		*ft_itoa(int n);
char		*ft_strtrim(char *s1, char *set);
char		*ft_strchr(char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_substr(char *s, int start, int len);
int			ft_strcharcmp(char *str, char c);
char		*ft_strjoin2(char *s1, char *s2);
void		*ft_calloc(size_t count, size_t size);
char		*cat_str(char *s);
int			ft_isdigit(char *str);
int			ft_int_strchr(char *str, char c);

#endif
