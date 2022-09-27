/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:25:07 by sryou             #+#    #+#             */
/*   Updated: 2022/09/27 16:50:34 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	runprocess(t_block *block)
{
	pid_t	pid;
	int		pipe_input[2];
	int		pipe_output[2];

	if (pipe(pipe_input) < 0 || pipe(pipe_output) < 0)
		error(strerror(errno));
	pid = fork();
	if (pid == -1) // fail to make child process
		error(strerror(errno));
	else if (pid == 0) // child process
	{
		// stdin redirection
		if (block->list_stdin != NULL)
		{
			close(pipe_input[1]);
			dup2(pipe_input[0], STDIN);
		}
		// stdout redirection
		if (block->list_stdout != NULL)
		{
			close(pipe_output[0]);
			dup2(pipe_output[1], STDOUT);
		}
		// execve
		printf("execve called\n");
		execve(find_exec(block->argv->content), list_to_charptrptr(block->argv), data.envp);
	}
	else // parent process
	{
		// stdin manage (pipe, redirection, heredoc...)
		if (block->list_stdin != NULL)
		{
			close(pipe_input[0]);
			stdin_manage(pipe_input[1], block->list_stdin);
		}
		// wait until child process ends
		wait(0);
		// stdout redirection (pipe, write...)
		if (block->list_stdout != NULL)
		{
			close(pipe_output[1]);
			stdout_manage(pipe_output[0], block->list_stdout);
		}
	}
}

void	make_redirection(t_block *block)
{
	t_list	*list_redir;
	t_redir	*redir;
	int		fd;

	list_redir = block->redir;
	while (list_redir)
	{
		redir = list_redir->content;
		if (redir->type == 1)
		{
			fd = open(redir->string, O_RDONLY);
			if (fd == -1)
				error(strerror(errno));
			add_stdin(block, fd);
		}
		else if (redir->type == 2)
		{
			fd = open(redir->string, O_WRONLY | O_CREAT | O_TRUNC, 0777);
			if (fd == -1)
				error(strerror(errno));
			add_stdout(block, fd);
		}
		else if (redir->type == 3)
			add_stdin(block, STDIN);
		else if (redir->type == 4)
		{
			fd = open(redir->string, O_WRONLY | O_CREAT | O_APPEND, 0777);
			if (fd == -1)
				error(strerror(errno));
			add_stdout(block, fd);
		}
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
		runprocess(block);
		block = block->next;
	}
}
