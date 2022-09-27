/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:45:36 by junekim           #+#    #+#             */
/*   Updated: 2022/09/27 17:36:10 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_dollar(t_block *block, char ch)
{
	if (block->quote[0])
		return (0);
	else if (ch == '$')
		return (1);
	return (0);
}

static int	is_end(t_block *block, char ch)
{
	if (is_in_quote(block))
		return (0);
	else if (!ch)
		return (1);
	else if (ch == '|')
		return (1);
	return (0);
}

static int	read_one_char(t_block *block, char **line, char **str)
{
	char	*env;

	create_empty(&env);
	while (!is_end(block, **line) && !is_space(block, **line) && \
		!is_redir(block, *line))
	{
		if (quote(block, **line))
		{
			(*line)++;
			continue ;
		}
		if (is_dollar(block, **line))
		{
			if (*env)
				*str = mini_join_str(*str, find_env(env, data->envp));
			block->dollar = is_dollar(block, **line);
			create_empty(&env);
			env = mini_join(env, '$');
			(*line)++;
			continue ;
		}
		if (block->dollar)
			env = mini_join(env, **line);
		else
			*str = mini_join(*str, **line);
		if (!(*str) || !env)
			error("read_one_char");
		(*line)++;
	}
	if (*env)
		*str = mini_join_str(*str, find_env(env, data->envp));
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
		if (is_space(block, *line))
		{
			line++;
			continue ;
		}
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
