/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chage_dollar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:45:21 by junekim           #+#    #+#             */
/*   Updated: 2022/10/04 21:05:20 by junekim          ###   ########seoul.kr  */
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
		if (quote(&block, *line))
		{	
			if (!block.dollar)
				changed_line = mini_join(changed_line, *line);
			line++;
			continue ;
		}
		if (is_dollar(&block, *line))
		{
			if (*env)
				changed_line = mini_join_str(changed_line, find_env(env, g_data->envp, 1));
			block.dollar = 1;
			free(env);
			create_empty(&env);
			env = mini_join(env, '$');
			line++;
			continue ;
		}
		if (block.dollar)
		{
			if (!is_end(&block, *line) && !is_space(&block, *line) && *line != '\n')
			{
				env = mini_join(env, *line);
				line++;
			}
			else
			{
				changed_line = mini_join_str(changed_line, find_env(env, g_data->envp, 1));
				block.dollar = 0;
				free(env);
				create_empty(&env);
				changed_line = mini_join(changed_line, *line);
				line++;
			}
		}
		else
		{
			changed_line = mini_join(changed_line, *line);
			line++;
		}
	}
	if (*env)
		changed_line = mini_join_str(changed_line, find_env(env, g_data->envp, 1));
	free(env);
	return (changed_line);
}
