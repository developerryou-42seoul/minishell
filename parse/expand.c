/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:52:14 by jonglee           #+#    #+#             */
/*   Updated: 2022/10/06 20:45:45 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_env(char *env, t_list *envp, int flag)
{
	if (!ft_strncmp(env, "$?", 2))
		return (ft_itoa(g_data->past_return));
	while (envp)
	{
		if (is_same_str(env + 1, ((t_dic *)envp->content)->key))
			return (((t_dic *)envp->content)->value);
		envp = envp->next;
	}
	if (flag)
		return ("");
	else
		return (NULL);
}

int	change_env(t_list *envp, char *key, char *value)
{
	while (envp)
	{
		if (is_same_str(key, ((t_dic *)envp->content)->key))
		{
			free(key);
			free(((t_dic *)envp->content)->value);
			((t_dic *)envp->content)->value = value;
			return (1);
		}
		envp = envp->next;
	}
	return (0);
}
