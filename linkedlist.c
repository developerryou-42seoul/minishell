/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:55:15 by junekim           #+#    #+#             */
/*   Updated: 2022/09/17 19:32:29 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_block(t_block_info *info, t_block *block)
{
	init_block(block);
	if (info->head == NULL)
	{
		info->head = block;
		info->tail = block;
		return ;
	}
	else
	{
		info->tail->next = block;
		block->prev = info->tail;
		info->tail = block;
	}
}

void	add_argv(t_block *block, char *str)
{
	t_list	*list;
	t_list	*cur;

	list = (t_list *)malloc(sizeof(t_list));
	init_list(list);
	list->string = str;
	if (!(block->argv))
	{
		block->argv = list;
		return ;
	}
	cur = block->argv;
	while (cur->next)
	{
		cur = cur->next;
	}
	cur->next = list;
}

void	add_redir(t_block *block, int type, char *str)
{
	t_list	*cur;
	t_list	*redir;

	redir = (t_list *)malloc(sizeof(t_list));
	init_list(redir);
	redir->type = type;
	redir->string = str;
	if (!(block->redir))
	{
		block->redir = redir;
		return ;
	}
	cur = block->redir;
	while (cur -> next)
	{
		cur = cur->next;
	}
	cur->next = redir;
}
