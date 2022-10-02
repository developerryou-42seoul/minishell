/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:52:14 by jonglee           #+#    #+#             */
/*   Updated: 2022/10/03 01:48:16 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_env(char *env, t_list *envp, int flag)
{
	size_t	len;

	if (!ft_strncmp(env, "$?", 2))
		return (ft_itoa(g_data->past_return));
	env++;
	len = ft_strlen(env);
	while (envp)
	{
		if (len == ft_strlen(((t_dic *)envp->content)->key) && 
		(ft_strncmp(env, ((t_dic *)envp->content)->key, len) == 0))
			return (((t_dic *)envp->content)->value);
		envp = envp->next;
	}
	if (flag)
		return ("");
	else
		return (NULL);
}
