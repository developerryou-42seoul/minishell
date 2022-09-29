/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonglee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:52:20 by jonglee           #+#    #+#             */
/*   Updated: 2022/09/29 14:52:22 by jonglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_list(t_list *list)
{
	ft_lstclear(&list, free);
	free(list);
}

void	free_block(t_block *block)
{
	free_list(block->argv);
	free_list(block->redir);
	free_list(block->list_stdin);
	free_list(block->list_stdout);
	free(block);
}

void	free_info(t_block_info *info)
{
	t_block	*temp_block;

	temp_block = info->head;
	while (info->head)
	{
		info->head = info->head->next;
		free_block(temp_block);
		temp_block = info->head;
	}
}
