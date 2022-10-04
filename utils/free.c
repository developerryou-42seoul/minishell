/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:52:20 by jonglee           #+#    #+#             */
/*   Updated: 2022/10/04 19:04:14 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_std(void *content)
{
	free(content);
}

void	free_redir(void *redir)
{
	free(((t_redir *)redir)->string);
	free(redir);
}

void	free_list(t_list *list, void del(void *))
{
	ft_lstclear(&list, del);
	free(list);
}

void	free_block(t_block *block)
{
	free_list(block->argv, free);
	free_list(block->redir, free_redir);
	free_list(block->list_stdin, free);
	free_list(block->list_stdout, free);
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
