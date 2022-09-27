/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:07:09 by junekim           #+#    #+#             */
/*   Updated: 2022/09/27 16:46:17 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_g_data(char **envp)
{
	data.envp = envp;
}

int	init_terminal(struct termios *t)
{
	tcgetattr(STDIN_FILENO, t);
	t->c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, t);
	return (0);
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
