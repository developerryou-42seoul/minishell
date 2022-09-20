/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:45:36 by junekim           #+#    #+#             */
/*   Updated: 2022/09/20 17:31:06 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_dollar(t_block *block, char ch)
{
	if (block->quote[0])
		return (0);
	if (ch == '$')
		return (1);
	return (0);
}

static int	read_one_char(t_block *block, char **line, char **str)
{
	char	*env;

	create_empty(&env);
	while (**line && !is_space(block, **line) && !is_redir(block, *line))
	{
		if (quote(block, **line))
		{
			(*line)++;
			continue ;
		}
		if (!block->dollar)
			block->dollar = is_dollar(block, **line);
		if (block->dollar)
			env = mini_join(env, **line);
		else
			*str = mini_join(*str, **line);
		if (!(*str))
			error("read_one_char");
		(*line)++;
	}
	if (*env)
		*str = mini_join_str(*str, "env");
	return (0);
}

static int	is_end(t_block *block, char ch)
{
	if (!ch)
		return (1);
	if (is_in_quote(block))
		return (0);
	if (ch == '|')
		return (1);
	return (0);
}

char	*parser_sub(char *line, t_block_info *info)
{
	t_block	*block;
	char	*str;
	char	*str_redir;
	int		type;

	block = (t_block *)malloc(sizeof(t_block));
	add_block(info, block);
	while (!is_end(block, *line))
	{
		if (!is_space(block, *line))
		{
			create_empty(&str);
			while (!is_end(block, *line) && !is_space(block, *line))
			{
				type = is_redir(block, line);
				if (type)
				{
					if (type >= 3)
						line++;
					line++;
					while (is_space(block, *line))
						line++;
					if (is_redir(block, line) || is_end(block, *line))
						error("parser_sub1");
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
					error("parser_sub2");
			}
		}
		else
			line++;
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
