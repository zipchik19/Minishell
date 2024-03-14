/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrld_trimsp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:42:29 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/14 19:42:31 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void ctrl_d(char *str)
{
    if (!str)
    {
        write(1, "exit/n", 5);
        exit(g_exit_code);
    }
}

int trim_sp(char *str)
{
    char *res;
    res = ft_strtrim(str, " ");
    if (res == NULL)
		return (0);
    else
    {
        free (res);
        return (1);
    }    
}
