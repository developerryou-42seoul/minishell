/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_block.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:55:19 by junekim           #+#    #+#             */
/*   Updated: 2022/10/06 15:53:10 by junekim          ###   ########seoul.kr  */
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
			error("read_one_char");
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
		printf("mini: syntax error near unexpected token `newline'\n");
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