/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:30:39 by sryou             #+#    #+#             */
/*   Updated: 2022/09/29 18:20:21 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**split_path(void)
{
	int		idx;
	char	**path;

	idx = 0;
	path = 0;
	while (data->envp[idx] != 0)
	{
		if (ft_strncmp(data->envp[idx], "PATH=", 5) == 0)
		path = ft_split(data->envp[idx] + 5, ':');
		idx++;
	}
	return (path);
}

char	*find_path(char *path, char *exec)
{
	char	*temp1;
	char	*temp2;

	temp1 = ft_strjoin(path, "/");
	if (temp1 == 0)
		error("execution path join");
	temp2 = ft_strjoin(temp1, exec);
	free(temp1);
	if (temp2 == 0)
		error("execution path join");
	if (access(temp2, X_OK) == 0)
		return (temp2);
	free(temp2);
	return (0);
}

char	*find_exec(char *exec)
{
	int		idx;
	char	**path;
	char	*ret;

	if (!ft_strlen(exec))
		error("invalid envp");
	if (ft_strncmp(exec, "/", 1) != 0 && \
	ft_strncmp(exec, "./", 2) != 0 && \
	ft_strncmp(exec, "../", 3) != 0)
	{
		path = split_path();
		if (path == 0)
			error("path split");
		idx = 0;
		while (path[idx] != 0)
		{
			ret = find_path(path[idx], exec);
			if (ret != 0)
				return (ret);
			idx++;
		}
		error("command not found");
	}
	return (exec);
}
