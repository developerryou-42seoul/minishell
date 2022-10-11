/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_block.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnam <jnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:55:19 by junekim           #+#    #+#             */
/*   Updated: 2022/10/11 14:57:31 by jnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	read_one_char(t_block *block, char **line, char **str)
{
	block->dollar = 0;
	while (is_esr(block, line))
	{
		if (quote(block, **line))
		{
			(*line)++;
			continue ;
		}
		*str = mini_join(*str, **line);
		if (!(*str))
			error(strerror(errno));
		(*line)++;
	}
}

int	read_redir(int type, char **line, t_block *block)
{
	char	*str_redir;

	if (type >= 3)
		(*line)++;
	(*line)++;
	while (is_space(block, **line))
		(*line)++;
	if (is_redir(block, *line) || is_end(block, **line))
	{
		ft_putstr_fd("mini: syntax error near unexpected token `newline'\n", 2);
		return (1);
	}
	create_empty(&str_redir);
	read_one_char(block, line, &str_redir);
	add_redir(block, type, str_redir);
	return (0);
}

int	read_block(char **line, t_block_info *info)
{
	int		type;
	t_block	*block;
	char	*str_argv;

	block = info->tail;
	type = is_redir(block, *line);
	if (type)
	{
		if (read_redir(type, line, block))
			return (1);
	}
	else
	{
		create_empty(&str_argv);
		read_one_char(block, line, &str_argv);
		add_argv(block, str_argv);
	}
	return (0);
}
