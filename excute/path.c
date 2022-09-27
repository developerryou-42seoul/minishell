/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:30:39 by sryou             #+#    #+#             */
/*   Updated: 2022/09/26 18:33:07 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    **split_path()
{
    int     idx;
    char    **path;

    idx = 0;
    path = 0;
    /**while (envp[idx] != 0)   
	{
		if (ft_strncmp(envp[idx], "PATH=", 5) == 0)
			path = ft_split(envp[idx] + 5, ':');
		idx++;
	}
    return (path);**/
    return 0;
}

char	*find_exec(char *exec)
{
    int     idx;
    char    **path;
    char    *temp1;
    char    *temp2;

	if (ft_strncmp(exec, "/", 1) != 0 && \
		ft_strncmp(exec, "./", 2) != 0 && \
		ft_strncmp(exec, "../", 3) != 0)
    {
        path = split_path();
        if (path == 0)
            error("path split error");
        idx = 0;
        while (path[idx] != 0)
        {
            temp1 = ft_strjoin(path[idx], "/");
            if (temp1 == 0)
                error("execution path join error");
            temp2 = ft_strjoin(temp1, exec);
            free(temp1);
            if (temp2 == 0)
                error("execution path join error");
            if (access(temp2, X_OK) == 0)
                return (temp2);
            free(temp2);
            idx++;
        }
        error("command not found");
    }
    return (exec);
}
