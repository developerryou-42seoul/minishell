/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnam <jnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 21:30:52 by jnam              #+#    #+#             */
/*   Updated: 2022/10/05 21:16:18 by jnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_invalid_arg(t_list *arg)
{
	char	*str;
	int		i;

	i = 1;
	str = arg->content;
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (1);
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

void	ft_unset(t_list *cur, t_list *prev, t_list *arg)
{
	t_dic	*dic;

	while (cur)
	{
		dic = cur->content;
		if (is_same_str(dic->key, arg->content))
		{
			if (prev)
			{
				prev->next = cur->next;
				cur->next = NULL;
			}
			free(dic->key);
			free(dic->value);
			free(dic);
			free(cur);
			break ;
		}
		prev = cur;
		cur = prev->next;
	}
}

int	builtin_unset(t_block *block)
{
	t_list	*arg;
	t_list	*cur;
	t_list	*prev;
	int		i;

	i = 1;
	arg = block->argv->next;
	if (block->prev)
		return (0);
	while (i < block->argc)
	{
		if (is_invalid_arg(arg))
			return (error_unset("not a valid identifier", arg->content));
		cur = g_data->envp;
		prev = NULL;
		ft_unset(cur, prev, arg);
		i++;
		arg = arg->next;
	}
	return (0);
}
