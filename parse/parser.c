/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:45:36 by junekim           #+#    #+#             */
/*   Updated: 2022/10/11 14:08:15 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*parser_sub(char *line, t_block_info *info)
{
	t_block	*block;

	block = (t_block *)malloc(sizeof(t_block));
	if (!block)
		error("malloc error");
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
			if (read_block(&line, info))
				return (NULL);
			if (is_in_quote(block))
			{
				printf("quote error\n");
				return (NULL);
			}
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
			return (1);
		}
		line = parser_sub(line, info);
		if (!line)
			return (1);
		if (*line == '|')
		{
			line ++;
			if (*line == '|' || *line == '\0')
			{
				printf("mini: syntax error near unexpected token `|'\n");
				return (1);
			}
		}
	}
	return (0);
}
