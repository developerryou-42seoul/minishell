/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:48:42 by junekim           #+#    #+#             */
/*   Updated: 2022/09/29 21:32:30 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_echo(t_block *block)
{
	(void)block;
	return (0);
}

int	builtin_unset(t_block *block)
{
	(void)block;
	return (0);
}

int	builtin_exit(t_block *block)
{
	(void)block;
	return (0);
}

int	check_builtins(t_block *block)
{
	char	*exec;

	exec = block->argv->content;
	if (is_same_str(exec, "echo") \
	|| is_same_str(exec, "cd") \
	|| is_same_str(exec, "pwd") \
	|| is_same_str(exec, "export") \
	|| is_same_str(exec, "unset") \
	|| is_same_str(exec, "env") \
	|| is_same_str(exec, "exit"))
		return (1);
	else
		return (0);
}

int	manage_builtins(t_block *block)
{
	char	*exec;

	exec = block->argv->content;
	if (is_same_str(exec, "echo"))
		return (builtin_echo(block));
	else if (is_same_str(exec, "cd"))
		return (builtin_cd(block));
	else if (is_same_str(exec, "pwd"))
		return (builtin_pwd(block));
	else if (is_same_str(exec, "export"))
		return (builtin_export(block));
	else if (is_same_str(exec, "unset"))
		return (builtin_unset(block));
	else if (is_same_str(exec, "env"))
		return (builtin_env(block));
	else if (is_same_str(exec, "exit"))
		return (builtin_exit(block));
	else
		return (255);
}
