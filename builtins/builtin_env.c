/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:08:45 by junekim           #+#    #+#             */
/*   Updated: 2022/09/29 21:35:28 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_env(t_block *block)
{
	int	i;

	i = 0;
<<<<<<< HEAD
	(void)block;
	//if (block->argc != 1)
		//return (1);
	while (data->envp[i])
=======
	if (block->argc != 1)
		return (1);
	while (g_data->envp[i])
>>>>>>> master
	{
		printf("%s\n", g_data->envp[i]);
		i++;
	}
	return (0);
}
