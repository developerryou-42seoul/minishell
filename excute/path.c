/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnam <jnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:30:39 by sryou             #+#    #+#             */
/*   Updated: 2022/10/11 02:35:20 by jnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**split_path(void)
{
	char	*value;
	char	**path;

	path = 0;
	value = find_env("$PATH", g_data->envp, 0);
	if (value != 0)
		path = ft_split(value, ':');
	return (path);
}

char	*find_path(char *path, char *exec)
{
	int		fd;
	char	*temp1;
	char	*temp2;

	temp1 = ft_strjoin(path, "/");
	if (temp1 == 0)
		error(strerror(errno));
	temp2 = ft_strjoin(temp1, exec);
	free(temp1);
	if (temp2 == 0)
		error(strerror(errno));
	fd = open(temp2, O_RDONLY);
	if (fd >= 0)
	{
		close(fd);
		return (temp2);
	}
	free(temp2);
	return (0);
}

char	*find_exec(char *exec)
{
	int		idx;
	char	**path;
	char	*ret;

	if (!ft_strlen(exec))
		g_data->past_return = error_cnf("command not found", exec);
	if (ft_strncmp(exec, "/", 1) != 0 && \
	ft_strncmp(exec, "./", 2) != 0 && \
	ft_strncmp(exec, "../", 3) != 0)
	{
		path = split_path();
		if (path == 0)
			error_path("No such file or directory", exec);
		idx = 0;
		while (path[idx] != 0)
		{
			ret = find_path(path[idx], exec);
			if (ret != 0)
				return (ret);
			idx++;
		}
		g_data->past_return = error_cnf("command not found", exec);
	}
	return (exec);
}
