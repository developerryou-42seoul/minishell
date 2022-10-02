/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_block.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:55:19 by junekim           #+#    #+#             */
/*   Updated: 2022/09/29 20:18:24 by junekim          ###   ########seoul.kr  */
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

static int	check_dollar(t_block *block, char **line, char **str, char **env)
{
	if (is_dollar(block, **line))
	{
		if (**env)
			*str = mini_join_str(*str, find_env(*env, g_data->envp, 1));
		block->dollar = is_dollar(block, **line);
		if (block->dollar)
			free(*env);
		create_empty(&(*env));
		*env = mini_join(*env, '$');
		(*line)++;
		return (1);
	}
	return (0);
}

static int	read_one_char(t_block *block, char **line, char **str)
{
	char	*env;

	create_empty(&env);
	block->dollar = 0;
	while (!is_end(block, **line) && !is_space(block, **line) && \
		!is_redir(block, *line))
	{
		if (quote(block, **line))
		{
			(*line)++;
			continue ;
		}
		if (check_dollar(block, line, str, &env))
			continue ;
		if (block->dollar)
			env = mini_join(env, **line);
		else
			*str = mini_join(*str, **line);
		if (!(*str) || !env)
			error("read_one_char");
		(*line)++;
	}
	if (*env)
		*str = mini_join_str(*str, find_env(env, g_data->envp, 1));
	free(env);
	return (0);
}

int	read_block(char **line, t_block_info *info, \
char **str_argv, char **str_redir)
{
	int		type;
	t_block	*block;

	block = info->tail;
	type = is_redir(block, *line);
	if (type)
	{
		if (type >= 3)
			(*line)++;
		(*line)++;
		while (is_space(block, **line))
			(*line)++;
		if (is_redir(block, *line) || is_end(block, **line))
			error("parser_sub1");
		create_empty(&(*str_redir));
		read_one_char(block, &(*line), &(*str_redir));
		add_redir(block, type, *str_redir);
		return (1);
	}
	else
	{
		read_one_char(block, &(*line), &(*str_argv));
		add_argv(block, *str_argv);
	}
	return (0);
}
