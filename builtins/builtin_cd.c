/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:17:41 by junekim           #+#    #+#             */
/*   Updated: 2022/10/10 17:33:55 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	export_env(char *pwd, char *oldpwd)
{
	t_list	list[2];

	list[0].content = pwd;
	list[0].next = &list[1];
	list[1].content = oldpwd;
	list[1].next = NULL;
	push_argv_to_envp(&list[0]);
	free(pwd);
	free(oldpwd);
}

static int	home_cd(char *home, t_block *block)
{
	char	*dir;

	dir = ft_strjoin(home, (char *)(block->argv->next->content) + 1);
	if (chdir(dir))
	{
		free(dir);
		return (1);
	}
	free(dir);
	return (0);
}

static int	init_cd(char **pwd, char **home)
{
	*pwd = find_env("$PWD", g_data->envp, 0);
	*home = find_env("$HOME", g_data->envp, 0);
	if (!(*home))
		ft_putstr_fd("mini: cd: HOME not set\n", 2);
	if (!(*pwd) || !(*home))
		return (1);
	return (0);
}

int	check_cd(t_block *block)
{
	if (block->prev || block->next)
		return (0);
	return (1);
}

int	builtin_cd(t_block *block)
{
	char	*dir;
	char	*pwd;
	char	*home;

	if (!check_cd(block))
		return (0);
	if (init_cd(&pwd, &home))
		return (1);
	if (block->argc == 1)
	{
		if (chdir(home))
			return (error_cd(strerror(errno), block->argv->next->content));
	}
	else if (*((char *)(block->argv->next->content)) == '~')
	{
		if (home_cd(home, block))
			return (error_cd(strerror(errno), block->argv->next->content));
	}
	else if (chdir((char *)block->argv->next->content))
		return (error_cd(strerror(errno), block->argv->next->content));
	dir = getcwd(NULL, 0);
	export_env(ft_strjoin("PWD=", dir), ft_strjoin("OLDPWD=", pwd));
	free(dir);
	return (0);
}
