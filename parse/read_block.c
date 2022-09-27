/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_block.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:55:19 by junekim           #+#    #+#             */
/*   Updated: 2022/09/27 18:08:53 by sryou            ###   ########.fr       */
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
			*str = mini_join_str(*str, find_env(*env, data->envp));
		block->dollar = is_dollar(block, **line);
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
		*str = mini_join_str(*str, find_env(env, data->envp));
	return (0);
}

int	read_block_redir(char **line, t_block_info *info, \
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
