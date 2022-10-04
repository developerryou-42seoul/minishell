/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:25:07 by sryou             #+#    #+#             */
/*   Updated: 2022/10/04 17:43:23 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	open_redirection_stdin(t_redir *redir, t_block *block)
{
	int		fd;
	int		pipe_fd[2];
	char	*buf;

	if (redir->type == 1)
	{
		fd = open(redir->string, O_RDONLY);
		if (fd == -1)
			error(strerror(errno));
		add_stdin(block, fd);
	}
	else if (redir->type == 3)
	{
		if (pipe(pipe_fd) < 0)
			error(strerror(errno));
		while (1)
		{
			ft_putstr_fd("heredoc> ", STDOUT);
			buf = get_next_line(STDIN);
			if (buf == 0)
				break ;
			if (ft_strlen(buf) - 1 == ft_strlen(redir->string) && \
			ft_strncmp(buf, redir->string, ft_strlen(redir->string)) == 0)
			{
				free(buf);
				close(pipe_fd[1]);
				break ;
			}
			ft_putstr_fd(buf, pipe_fd[1]);
			free(buf);
		}
		add_stdin(block, pipe_fd[0]);
	}
}

void	open_redirection_stdout(t_redir *redir, t_block *block)
{
	int	fd;

	if (redir->type == 2)
	{
		fd = open(redir->string, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (fd == -1)
			error(strerror(errno));
		add_stdout(block, fd);
	}
	else if (redir->type == 4)
	{
		fd = open(redir->string, O_WRONLY | O_CREAT | O_APPEND, 0777);
		if (fd == -1)
			error(strerror(errno));
		add_stdout(block, fd);
	}
}

void	make_redirection(t_block *block)
{
	t_list	*list_redir;
	t_redir	*redir;

	list_redir = block->redir;
	while (list_redir)
	{
		redir = list_redir->content;
		if (redir->type == 1 || redir->type == 3)
			open_redirection_stdin(redir, block);
		else if (redir->type == 2 || redir->type == 4)
			open_redirection_stdout(redir, block);
		else
			error("redir error");
		list_redir = list_redir->next;
	}
}

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
