/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:07:09 by junekim           #+#    #+#             */
/*   Updated: 2022/09/25 14:13:05 by jonglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_g_data(char **envp)
{
	data.envp = envp;
	//
	//
}

int	init_terminal(struct termios *t)
{
	tcgetattr(STDIN_FILENO, t);
	t->c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, t);
	return (0);
}

void	init_list(t_list *list)
{
	list->next = NULL;
	list->string = NULL;
	list->type = -1;
}

void	init_block(t_block *block)
{
	block->argc = 0;
	block->argv = NULL;
	block->next = NULL;
	block->prev = NULL;
	block->redir = NULL;
	block->quote[0] = 0;
	block->quote[1] = 0;
	block->dollar = 0;
}
