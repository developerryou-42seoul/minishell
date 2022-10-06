/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:25:07 by sryou             #+#    #+#             */
/*   Updated: 2022/10/06 19:17:15 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	children_heredoc(t_redir *redir, int pipe_fd[])
{
	char	*buf;

	redir_terminal(&g_data->t);
	close(pipe_fd[0]);
	while (1)
	{
		ft_putstr_fd("> ", STDOUT);
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
	exit(1);
}

void	open_redirection_heredoc(t_redir *redir, t_block *block)
{
	pid_t	pid;
	int		pipe_fd[2];

	if (pipe(pipe_fd) < 0)
		error(strerror(errno));
	pid = fork();
	if (pid == -1)
		error(strerror(errno));
	else if (pid == 0)
		children_heredoc(redir, pipe_fd);
	else
	{
		signal(SIGQUIT, SIG_IGN);
		wait(0);
		close(pipe_fd[1]);
		add_stdin(block, pipe_fd[0]);
	}
}

void	open_redirection_stdin(t_redir *redir, t_block *block)
{
	int		fd;

	if (redir->type == 1)
	{
		fd = open(redir->string, O_RDONLY);
		if (fd == -1)
			error(strerror(errno));
		add_stdin(block, fd);
	}
	else if (redir->type == 3)
		open_redirection_heredoc(redir, block);
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
