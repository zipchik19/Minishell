/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_inout.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:41:00 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/14 19:41:02 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	redirection_input(char *file, int i)
{
	int	fd;

	fd = open(file, O_RDONLY, 0644);
	if (fd < 0)
	{
		error_msg(NULL, "syntax error near unexpected token `newline", 258);
		close(fd);
		return ;
	}
	if (i == 1)
		dup2(fd, 0);
	close(fd);
}

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
