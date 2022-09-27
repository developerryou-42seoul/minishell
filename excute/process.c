/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:58:13 by sryou             #+#    #+#             */
/*   Updated: 2022/09/27 17:59:10 by sryou            ###   ########.fr       */
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
	printf("execve called\n");
	execve(find_exec(block->argv->content), \
		list_to_charptrptr(block->argv), data->envp);
}

void	parentprocess(int pipe_input[], int pipe_output[], t_block *block)
{
	if (block->list_stdin != NULL)
	{
		close(pipe_input[0]);
		stdin_manage(pipe_input[1], block->list_stdin);
	}
	wait(0);
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
