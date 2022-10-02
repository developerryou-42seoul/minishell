/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:55:15 by junekim           #+#    #+#             */
/*   Updated: 2022/10/03 00:18:30 by sryou            ###   ########.fr       */
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
