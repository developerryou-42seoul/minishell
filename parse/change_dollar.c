/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:45:21 by junekim           #+#    #+#             */
/*   Updated: 2022/10/06 15:53:26 by junekim          ###   ########seoul.kr  */
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

static int	is_finish_dollar(char ch)
{
	if (ch == '\0' || ch == '|' || ch == '\n' || \
	ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f'
		|| ch == '\r' || ch == ' ')
		return (1);
	return (0);
}

static void	change_dollar_sub(t_block *block, char **env, \
char **changed_line, int dollar)
{
	if (**env)
		*changed_line = mini_join_str(*changed_line, \
	find_env(*env, g_data->envp, 1));
	block->dollar = dollar;
	free(*env);
	create_empty(env);
}

static void	change_dollar_sub2(t_block *block, char **env, \
char **changed_line, char line)
{
	if (quote(block, line))
	{	
		if (block->dollar)
			change_dollar_sub(block, env, changed_line, 0);
		*changed_line = mini_join(*changed_line, line);
	}
	else if (is_dollar(block, line))
	{
		change_dollar_sub(block, env, changed_line, 1);
		*env = mini_join(*env, '$');
	}
	else if (block->dollar)
	{
		if (!is_finish_dollar(line))
			*env = mini_join(*env, line);
		else
		{
			change_dollar_sub(block, env, changed_line, 0);
			*changed_line = mini_join(*changed_line, line);
		}
	}
	else
		*changed_line = mini_join(*changed_line, line);
}

char	*change_dollar(char *line)
{
	char	*env;
	char	*changed_line;
	t_block	block;

	create_empty(&changed_line);
	create_empty(&env);
	init_block(&block);
	while (*line)
	{
		change_dollar_sub2(&block, &env, &changed_line, *line);
		line++;
	}
	if (*env)
		changed_line = mini_join_str(changed_line, \
		find_env(env, g_data->envp, 1));
	free(env);
	return (changed_line);
}
