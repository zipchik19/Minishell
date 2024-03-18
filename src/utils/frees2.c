/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:56:03 by nbadalia          #+#    #+#             */
/*   Updated: 2024/03/18 15:56:06 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	matrix_free(char **env_split)
{
	int	j;

	j = 0;
	while (env_split && env_split[j])
	{
		free(env_split[j]);
		j++;
	}
	free(env_split);
}
