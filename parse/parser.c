/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:45:36 by junekim           #+#    #+#             */
/*   Updated: 2022/09/29 16:46:07 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*parser_sub(char *line, t_block_info *info)
{
	t_block	*block;
	char	*str_argv;
	char	*str_redir;

	block = (t_block *)malloc(sizeof(t_block));
	add_block(info, block);
	while (!is_end(block, *line))
	{
		if (is_space(block, *line))
		{
			line++;
			continue ;
		}
		create_empty(&str_argv);
		while (!is_end(block, *line) && !is_space(block, *line))
		{
			read_block(&line, info, &str_argv, &str_redir);
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
		line = parser_sub(line, info);
		if (*line == '|')
			line ++;
		if (*line == '|')
			error("parser");
	}
	print_info(info);
	return (0);
}
