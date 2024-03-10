#include "../../minishell.h"

void    ft_putstr_fd(char *str, int fd)
{
    write(fd, str, ft_strlen(str));

}

void    error_msg(char *cmd, char *str, int numb)
{
	g_exit_code = numb;
	ft_putstr_fd("minishell : ", 2);
	if (cmd)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
}
