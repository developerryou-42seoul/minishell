/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:35:21 by junekim           #+#    #+#             */
/*   Updated: 2022/10/10 14:12:24 by jonglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_exit(t_block *block)
{
	if (block->argv != 0 && \
		!is_same_str(block->argv->content, "exit"))
		return (0);
	if (block->prev || block->next)
		return (0);
	if (block->argc == 2)
		return (1);
	else if (block->argc > 2)
	{
		if (check_numeric(block) && \
			check_atol((char *)block->argv->next->content))
			return (0);
	}
	return (1);
}

void	print_exit(char *str, t_block *block, int flag)
{
	printf("exit\n");
	if (flag == 1)
	{
		printf("mini: exit: %s: %s\n", \
			(char *)block->argv->next->content, str);
		exit(255);
	}
	else
		printf("mini: exit: %s\n", str);
}

int	builtin_exit(t_block *block)
{
	if (block->argc == 2)
	{
		if (check_numeric(block) && \
			check_atol((char *)block->argv->next->content))
		{
			if (!block->next && !block->prev)
				printf("exit\n");
			exit(ft_atol((char *)block->argv->next->content));
		}
		else
			print_exit("numeric argument required", block, 1);
	}
	else if (block->argc > 2)
	{
		if (check_numeric(block) && \
			check_atol((char *)block->argv->next->content))
			print_exit("too many arguments", block, 0);
		else
			print_exit("numeric argument required", block, 1);
		return (1);
	}
	if (!block->next && !block->prev)
		printf("exit\n");
	exit(0);
}

int	parent_exit(t_block *block)
{
	if (block->argc == 2)
	{
		if (check_numeric(block) && \
			check_atol((char *)block->argv->next->content))
			return (ft_atol(block->argv->next->content));
		return (255);
	}
	else if (block->argc > 2)
		return (255);
	else
		return (0);
	return (0);
}
