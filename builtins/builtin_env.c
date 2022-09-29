/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:08:45 by junekim           #+#    #+#             */
/*   Updated: 2022/09/29 20:13:13 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_env(t_block *block)
{
	int	i;

	i = 0;
	if (block->argc != 1)
		return (1);
	while (data->envp[i])
	{
		printf("%s\n", data->envp[i]);
		i++;
	}
	return (0);
}
