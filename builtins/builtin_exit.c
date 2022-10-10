/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:35:21 by junekim           #+#    #+#             */
/*   Updated: 2022/10/10 18:03:57 by jonglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_exit(t_block *block)
{
	if (block->argv != 0 && \
		is_same_str(block->argv->content, "exit"))
	{
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
	return (0);
}

void	print_exit_error(char *str, t_block *block, int flag)
{
	if (!block->next && !block->prev)
		ft_putstr_fd("exit\n", 2);
	if (flag == 1)
	{
		ft_putstr_fd("mini: exit: ", 2);
		ft_putstr_fd((char *)block->argv->next->content, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\n", 2);
		exit(255);
	}
	else
	{
		ft_putstr_fd("mini: exit: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\n", 2);
	}
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
			print_exit_error("numeric argument required", block, 1);
	}
	else if (block->argc > 2)
	{
		if (check_numeric(block) && \
			check_atol((char *)block->argv->next->content))
			print_exit_error("too many arguments", block, 0);
		else
			print_exit_error("numeric argument required", block, 1);
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
