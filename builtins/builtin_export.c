/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:36:16 by junekim           #+#    #+#             */
/*   Updated: 2022/10/06 21:21:21 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	sort(char **key_arr, int len)
{
	int	idx;
	int	j;
	
	idx = 1;
	while (idx < len)
	{
		j = idx;
		while (j > 0)
		{
			if (ft_strncmp(key_arr[j - 1], key_arr[j], ft_strlen(key_arr[j])) > 0)
				swap(&key_arr[j - 1], &key_arr[j]);
			j--;
		}
		idx++;
	}
}
char	**make_key_arr(t_list *envp)
{
	int		len;
	int		idx;
	char	**key_arr;

	len = ft_lstsize(envp);
	key_arr = malloc(sizeof(char *) * len);
	idx = 0;
	while (envp)
	{
		key_arr[idx++] = ((t_dic *)(envp->content))->key;
		envp = envp->next;
	}
	sort(key_arr, len);
	return (key_arr);
}

void	print_export(t_list *envp)
{
	int		idx;
	char	**key_arr;
	char	*env;
	char	*value;

	key_arr = make_key_arr(envp);
	idx = 0;
	while (idx < ft_lstsize(envp))
	{
		ft_putstr_fd("declare -x ", STDOUT);
		ft_putstr_fd(key_arr[idx], STDOUT);
		ft_putchar_fd('=', STDOUT);
		env = mini_join_dollar(key_arr[idx++]);
		value = find_env(env, envp, 1);
		while (*value)
		{
			if (*value == '$')
				ft_putchar_fd('\\', STDOUT);
			ft_putchar_fd(*value, STDOUT);
			value++;
		}
		ft_putchar_fd('\n', STDOUT);
		free(env);
	}
	free(key_arr);
}

int	builtin_export(t_block *block)
{
	if (block->prev)
		return (0);
	if (block->argv->next == 0)
		print_export(g_data->envp);
	else
		return (push_argv_to_envp(block->argv->next));
	return (0);
}
