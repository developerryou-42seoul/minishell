/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:45:36 by junekim           #+#    #+#             */
/*   Updated: 2022/09/20 14:00:33 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	read_one_char(t_block *block, char **line, char **str)
{
	while (**line && !is_space(block, **line) && !is_redir(block, *line))
	{
		if (!quote(block, **line))
			*str = mini_join(*str, **line);
		if (!(*str))
		{
			printf("error\n");
			exit(1);
		}
		(*line)++;
	}
	return (0);
}

static int	is_end(char ch)
{
	if (!ch || ch == '|')
		return (1);
	return (0);
}

int	parser_sub(char *line, t_block_info *info)
{
	t_block	*block;
	char	*str;
	char	*str_redir;
	int		type;

	block = (t_block *)malloc(sizeof(t_block));
	add_block(info, block);
	while (!is_end(*line))
	{
		if (!is_space(block, *line))
		{
			create_empty(&str);
			while (!is_end(*line) && !is_space(block, *line))
			{
				type = is_redir(block, line);
				if (type)
				{
					if (type >= 3)
						line++;
					line++;
					while (is_space(block, *line))
						line++;
					if (is_redir(block, line) || is_end(*line))
						error();
					create_empty(&str_redir);
					read_one_char(block, &line, &str_redir);
					add_redir(block, type, str_redir);
				}
				else
				{
					read_one_char(block, &line, &str);
					add_argv(block, str);
				}
				if (is_in_quote(block))
					error();
			}
		}
		else
			line++;
	}
	return (0);
}

int	parser(char *line, t_block_info *info)
{
	while (*line)
	{
		parser_sub(line, info);
		while (*line && *line != '|')
			line++;
		if (*line == '|')
			line ++;
		if (*line == '|')
			error();
	}
	print_info(info);
	return (0);
}
