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

int	ft_unset(t_block *block)
{
	char	*env_name;
	t_list	*cur;
	t_list	*prev;

	env_name = block->argv->next;
	cur = data->envp;
	prev = NULL;
	if (block->argc < 2)
		return (1);	
	while (cur)
	{
		if (!ft_strncmp(cur->content, env_name, ft_strlen(env_name)))
		{
			if (prev)
			{
				prev->next = cur->next;
				cur->next = NULL;
			}
			free(cur);
			break ;
		}
		prev = cur;
		cur = cur->next;
	}
	return (0);
}
