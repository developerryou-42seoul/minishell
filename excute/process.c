/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:58:13 by sryou             #+#    #+#             */
/*   Updated: 2022/10/04 17:56:01 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	childprocess(int pipe_input[], int pipe_output[], t_block *block)
{
	reset_terminal(&g_data->t);
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
		execve(find_exec(block->argv->content), \
			list_to_charptrptr(block->argv), \
			diclist_to_charptrptr(g_data->envp));
		error(strerror(errno));
	}
}

void	parentprocess(int pipe_input[], int pipe_output[], t_block *block)
{
	int	status;

	if (block->list_stdin != NULL)
	{
		close(pipe_input[0]);
		stdin_manage(pipe_input[1], block->list_stdin);
	}
	if (wait(&status) == -1)
		g_data->past_return = 1;
	if (check_exit(block))
		exit(0);
	if (status != 0)
		g_data->past_return = status / 256;
	else
		g_data->past_return = 0;
	if (block->list_stdout != NULL)
	{
		close(pipe_output[1]);
		stdout_manage(pipe_output[0], block->list_stdout);
	}
}

void	runprocess(t_block *block)
{
	pid_t	pid;
	int		pipe_input[2];
	int		pipe_output[2];

	if (pipe(pipe_input) < 0 || pipe(pipe_output) < 0)
		error(strerror(errno));
	pid = fork();
	if (pid == -1)
		error(strerror(errno));
	else if (pid == 0)
		childprocess(pipe_input, pipe_output, block);
	else
		parentprocess(pipe_input, pipe_output, block);
}
