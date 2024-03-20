#include "../../minishell.h"

void	redirection_output(char *file, int i)
{
	int	len;
	int	fd;

	len = ft_strlen(file);
	if (len == 0)
	{
		printf("minishell: : No such file or directory\n");
	}
	else
	{
	fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (i)
		{
			dup2(fd, 1);
		}
		close(fd);
	}
}

void	redirection_output_append(char *file, int i)
{
	int	fd;

	fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (i)
	{
		dup2(fd, 1);
	}
	close(fd);
}

void	redirection_input(char *file, int i)
{
	int	fd;

	fd = open(file, O_RDONLY, 0644);
	if (fd < 0)
	{
		print_error(NULL, "syntax error near unexpected token `newline", 258);
		close(fd);
		return ;
	}
	if (i)
		dup2(fd, 0);
	close(fd);
}

int	status_check(char *file, char *s)
{
	if (g_exit_code == -14)
	{
		g_exit_code = 1;
		free(file);
		free(s);
		return (1);
	}
	return (0);
}
