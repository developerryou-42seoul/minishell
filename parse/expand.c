/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:52:14 by jonglee           #+#    #+#             */
/*   Updated: 2022/09/29 20:17:46 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_env(char *env, char **envp, int flag)
{
	char	*temp_env;
	int		len;

	if (!ft_strncmp(env, "$?", 2))
		return (ft_itoa(g_data->past_return));
	create_empty(&temp_env);
	temp_env = mini_join_str(temp_env, ++env);
	temp_env = mini_join(temp_env, '=');
	len = ft_strlen(temp_env);
	while (*envp)
	{
		if (!(ft_strncmp(temp_env, *envp, len)))
		{
			free(temp_env);
			return (*envp + len);
		}
		envp++;
	}
	free(temp_env);
	if (flag)
		return ("");
	else
		return (NULL);
}
