/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:48:42 by junekim           #+#    #+#             */
/*   Updated: 2022/10/04 20:11:53 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_builtins_after_fork(t_block *block)
{
	char	*exec;

	if (block->argv == 0)
		return (0);
	exec = block->argv->content;
	if (is_same_str(exec, "echo"))
		return (1);
	else if (is_same_str(exec, "pwd"))
		return (1);
	else if (is_same_str(exec, "export") && block->argv->next == 0)
		return (1);
	else if (is_same_str(exec, "env"))
		return (1);
	else if (is_same_str(exec, "exit"))
		return (1);
	else
		return (0);
}

int	excute_builtins_after_fork(t_block *block)
{
	char	*exec;

	if (block->argv == 0)
		return (255);
	exec = block->argv->content;
	if (is_same_str(exec, "echo"))
		return (builtin_echo(block));
	else if (is_same_str(exec, "pwd"))
		return (builtin_pwd(block));
	else if (is_same_str(exec, "export") && block->argv->next == 0)
		return (builtin_export(block));
	else if (is_same_str(exec, "env"))
		return (builtin_env(block));
	else if (is_same_str(exec, "exit"))
		return (builtin_exit(block));
	else
		return (255);
}

int	check_builtins_before_fork(t_block *block)
{
	char	*exec;

	if (block->argv == 0)
		return (0);
	exec = block->argv->content;
	if (is_same_str(exec, "export") && block->argv->next != 0)
		return (1);
	else if (is_same_str(exec, "unset"))
		return (1);
	else if (is_same_str(exec, "cd"))
		return (1);
	else
		return (0);
}

int	excute_builtins_before_fork(t_block *block)
{
	char	*exec;

	if (block->argv == 0)
		return (g_data->past_return);
	exec = block->argv->content;
	if (is_same_str(exec, "export") && block->argv->next != 0)
		return (builtin_export(block));
	else if (is_same_str(exec, "unset"))
		return (builtin_unset(block));
	else if (is_same_str(exec, "cd"))
		return (builtin_cd(block));
	else
		return (g_data->past_return);
}
