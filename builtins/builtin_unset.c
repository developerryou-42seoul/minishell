/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnam <jnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 21:30:52 by jnam              #+#    #+#             */
/*   Updated: 2022/09/30 21:30:53 by jnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(t_list *cur, t_list *prev, t_list *env, int count)
{
	t_dic	*dic;

	while (cur)
	{
		dic = cur->content;
		if (is_same_str(dic->key, env->content))
		{
			if (prev)
			{
				prev->next = cur->next;
				cur->next = NULL;
			}
			free(dic);
			free(cur);
			count++;
			break ;
		}
		prev = cur;
		cur = cur->next;
	}
}

int	builtin_unset(t_block *block)
{
	t_list	*env;
	t_list	*cur;
	t_list	*prev;
	int		i;
	int		count;

	i = 1;
	count = 0;
	env = block->argv->next;
	while (i < block->argc)
	{
		cur = g_data->envp;
		prev = NULL;
		ft_unset(cur, prev, env, count);
		i++;
		env = env->next;
	}
	if (count + 1 == block->argc)
		return (0);
	else
		return (127);
}
