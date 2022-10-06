/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:17:41 by junekim           #+#    #+#             */
/*   Updated: 2022/10/06 20:43:57 by junekim          ###   ########seoul.kr  */
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
		return (error_cd(strerror(errno), block->argv->next->content));
	free(dir);
	return (0);
}

static int	init_cd(char **pwd, char **home)
{
	*pwd = find_env("$PWD", g_data->envp, 0);
	*home = find_env("$HOME", g_data->envp, 0);
	if (!(*home))
		printf("mini: cd: HOME not set\n");
	if (!(*pwd) || !(*home))
		return (1);
	return (0);
}

int	builtin_cd(t_block *block)
{
	char	*dir;
	char	*pwd;
	char	*home;

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
			return (home_cd(home, block));
	}
	else if (chdir((char *)block->argv->next->content))
		return (error_cd(strerror(errno), block->argv->next->content));
	dir = getcwd(NULL, 0);
	export_env(ft_strjoin("PWD=", dir), ft_strjoin("OLDPWD=", pwd));
	free(dir);
	return (0);
}
