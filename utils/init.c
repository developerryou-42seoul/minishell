/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:07:09 by junekim           #+#    #+#             */
/*   Updated: 2022/10/06 19:57:10 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_list_envp(char **envp_arr)
{
	char	*key;
	char	*value;
	int		i;

	i = 0;
	while (envp_arr[i])
	{
		key = split_key(envp_arr[i]);
		value = split_value(envp_arr[i]);
		if (key != 0 && value != 0)
			add_envp(key, value);
		i++;
	}
}

void	init_g_data(char **envp)
{
	g_data = malloc(sizeof(t_data));
	init_list_envp(envp);
	g_data->past_return = 0;
	g_data->past_return_charptr = 0;
}

void	init_block(t_block *block)
{
	block->argc = 0;
	block->path = NULL;
	block->argv = NULL;
	block->next = NULL;
	block->prev = NULL;
	block->redir = NULL;
	block->list_stdin = NULL;
	block->list_stdout = NULL;
	block->quote[0] = 0;
	block->quote[1] = 0;
	block->dollar = 0;
}
