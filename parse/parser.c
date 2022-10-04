/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:45:36 by junekim           #+#    #+#             */
/*   Updated: 2022/10/04 21:20:05 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*parser_sub(char *line, t_block_info *info)
{
	t_block	*block;

	block = (t_block *)malloc(sizeof(t_block));
	add_block(info, block);
	while (!is_end(block, *line))
	{
		if (is_space(block, *line))
		{
			line++;
			continue ;
		}
		while (!is_end(block, *line) && !is_space(block, *line))
		{
			read_block(&line, info);
			if (is_in_quote(block))
				error("parser_sub2");
		}
	}
	return (line);
}

int	parser(char *line, t_block_info *info)
{
	while (*line)
	{
		while (*line == '\t' || *line == '\n' || *line == '\v' || *line == '\f' \
		|| *line == '\r' || *line == ' ')
			line++;
		if (*line == '|')
		{
			printf("mini: syntax error near unexpected token `|'\n");
			return (0);
		}
		line = parser_sub(line, info);
		if (*line == '|')
		{
			line ++;
			if (*line == '|' || *line == '\0')
				error("parser");
		}
	}
	print_info(info);
	return (0);
}
