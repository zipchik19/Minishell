#include "../../minishell.h"

void	print_error(char *cmd, char *str, int code)
{
	g_exit_code = code;
	ft_putstr_fd("miniHell: ", 2);
	if (cmd)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
}
void	print_error_exit(char *cmd,char *val, char *str, int code)
{
	g_exit_code = code;
	ft_putstr_fd("miniHell: ", 2);
	if (cmd)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putstr_fd(val, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
}
void	ft_putstr_fd_endl(char *s, int fd, int len)
{
	write(fd, s, ft_strlen(s));
	if (len)
		write(fd, "\n", 1);
}
