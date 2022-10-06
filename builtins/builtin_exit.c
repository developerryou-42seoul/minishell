/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:35:21 by junekim           #+#    #+#             */
/*   Updated: 2022/10/04 20:28:28 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_numeric(t_block *block)
{
	char	*str;

	str = block->argv->next->content;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '\0')
		return (0);
	while (*str >= '0' && *str <= '9')
		str++;
	if (*str != '\0')
		return (0);
	return (1);
}

int	check_exit(t_block *block)
{
	if (block->argv != 0 && \
		is_same_str(block->argv->content, "exit") && \
		!block->next && !block->prev)
	{
		if (block->argc > 2 && check_numeric(block))
			return (0);
		printf("exit\n");
		return (1);
	}
	return (0);
}

int	builtin_exit(t_block *block)
{
	if (block->argc > 2)
	{
		if (check_numeric(block))
		{
			printf("mini: exit: too many arguments\n");
			return (1);
		}
		printf("mini: exit: %s: numeric argument required\n", \
				(char *)block->argv->next->content);
		exit(255);
	}
	else if (block->argc == 2)
	{
		if (!check_numeric(block))
		{
			printf("mini: exit: %s: numeric argument required\n", \
					(char *)block->argv->next->content);
			exit(255);
		}
		exit (ft_atol(block->argv->next->content));
	}
	else
		exit(0);
	return (0);
}
