/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:08:45 by junekim           #+#    #+#             */
/*   Updated: 2022/10/04 17:35:14 by junekim          ###   ########seoul.kr  */
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
