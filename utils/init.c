/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:07:09 by junekim           #+#    #+#             */
/*   Updated: 2022/09/29 18:41:35 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*init_list_envp(char **envp_arr)
{
	t_list	*envp;
	int		i;

	i = 0;
	envp = NULL;
	while(envp_arr[i])
		ft_lstadd_back(&envp, ft_lstnew(envp_arr[i++]));
	return (envp);
}

void	init_g_data(char **envp)
{
	g_data = malloc(sizeof(t_data));
	// g_data->envp = init_list_envp(envp);
	g_data->envp = envp;
	g_data->past_return = 0;
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
