/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:08:45 by junekim           #+#    #+#             */
/*   Updated: 2022/10/03 01:17:56 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_envp(t_list	*envp)
{
	char	*env;

	while (envp)
	{
		env = dic_to_charptr(envp->content);
		printf("%s\n", env);
		free(env);
		envp = envp->next;
	}
}

int	builtin_env(t_block *block)
{
	int		i;
	
	i = 0;
	if (block->argc != 1)
		return (1);
	print_envp(g_data->envp);
	return (0);
}
