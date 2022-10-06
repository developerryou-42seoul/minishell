/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:25:07 by sryou             #+#    #+#             */
/*   Updated: 2022/10/06 21:28:00 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	excute(t_block_info *info)
{
	t_block	*block;

	block = info->head;
	while (block)
	{
		if (block->prev != 0)
			add_stdin(block, block->prev->pipe_fd[0]);
		if (block->next != 0)
		{
			if (pipe(block->pipe_fd) < 0)
				error(strerror(errno));
			add_stdout(block, block->pipe_fd[1]);
		}
		make_redirection(block);
		if (check_builtins_before_fork(block))
			g_data->past_return = excute_builtins_before_fork(block);
		else
			runprocess(block);
		block = block->next;
	}
}
