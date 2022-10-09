/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:58:13 by sryou             #+#    #+#             */
/*   Updated: 2022/10/06 15:48:34 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	childprocess(int pipe_input[], int pipe_output[], t_block *block)
{
	if (block->list_stdin != NULL)
	{
		close(pipe_input[1]);
		dup2(pipe_input[0], STDIN);
	}
	if (block->list_stdout != NULL)
	{
		close(pipe_output[0]);
		dup2(pipe_output[1], STDOUT);
	}
	if (check_builtins_after_fork(block))
		exit(excute_builtins_after_fork(block));
	else
	{
		if (block->argv == 0)
			exit(0);
		else
			execve(find_exec(block->argv->content), \
				list_to_charptrptr(block->argv), \
				diclist_to_charptrptr(g_data->envp));
		error(strerror(errno));
	}
}

void	parentprocess(int pipe_input[], int pipe_output[], t_block *block)
{
	int	status;
	
	close(pipe_input[0]);
	if (wait(&status) == -1)
		g_data->past_return = 1;
	if (check_exit(block))
		exit(excute_builtins_after_fork(block));
	if (status != 0)
		g_data->past_return = status / 256;
	else
		g_data->past_return = 0;
	close(pipe_output[1]);
}

void	runprocess(t_block *block)
{
	pid_t	pid;
	int		pipe_input[2];
	int		pipe_output[2];

	if (pipe(pipe_input) < 0 || pipe(pipe_output) < 0)
		error(strerror(errno));
	if (block->list_stdin != NULL)
		stdin_manage(pipe_input[1], block->list_stdin);
	pid = fork();
	if (pid == -1)
		error(strerror(errno));
	else if (pid == 0)
		childprocess(pipe_input, pipe_output, block);
	else
		parentprocess(pipe_input, pipe_output, block);
	if (block->list_stdout != NULL)
		stdout_manage(pipe_output[0], block->list_stdout);
}
