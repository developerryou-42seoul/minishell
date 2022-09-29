/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonglee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:52:14 by jonglee           #+#    #+#             */
/*   Updated: 2022/09/29 14:52:15 by jonglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_env(char *env, char **envp)
{
	char	*temp_env;
	int		len;

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
	return ("");
}
