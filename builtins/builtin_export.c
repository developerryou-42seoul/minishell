/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:36:16 by junekim           #+#    #+#             */
/*   Updated: 2022/10/04 17:36:16 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_valid_key(char *key)
{
	int	i;

	i = 1;
	if (!ft_isalpha(key[0]) && key[0] != '_')
		return (1);
	while (key[i])
	{
		if (!ft_isalnum(key[i]) && key[i] != '_')
			return (1);
		if (key[i] == '\t' || key[i] == '\n' || key[i] == '\v' \
		|| key[i] == '\f' || key[i] == '\r' || key[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	push_argv_to_envp(t_list *argv)
{
	char	*key;
	char	*value;

	while (argv)
	{
		key = split_key(argv->content);
		if (!key)
			return (0);
		if (is_valid_key(key))
			return (error_export("not a valid identifier", argv->content));
		value = split_value(argv->content);
		if (key != 0 && value != 0)
		{
			if (!change_env(g_data->envp, key, value))
				add_envp(key, value);
		}
		argv = argv->next;
	}
	return (0);
}

int	builtin_export(t_block *block)
{
	if (block->prev)
		return (0);
	if (block->argv->next == 0)
		print_envp(g_data->envp);
	else
		return (push_argv_to_envp(block->argv->next));
	return (0);
}
