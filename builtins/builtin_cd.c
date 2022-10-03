/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:17:41 by junekim           #+#    #+#             */
/*   Updated: 2022/10/03 16:50:12 by junekim          ###   ########seoul.kr  */
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
		return (errno);
	free(dir);
	return (0);
}

static int	init_cd(t_block *block, char **pwd, char **home)
{
	if (block->argc > 2)
		return (1);
	*pwd = find_env("$PWD", g_data->envp, 0);
	*home = find_env("$HOME", g_data->envp, 0);
	if (!(*pwd) || !(*home))
		return (1);
	return (0);
}

int	builtin_cd(t_block *block)
{
	char	*dir;
	char	*pwd;
	char	*home;

	if (init_cd(block, &pwd, &home))
		return (1);
	if (block->argc == 1)
	{
		if (chdir(home))
			return (errno);
	}
	else if (*((char *)(block->argv->next->content)) == '~')
	{
		if (home_cd(home, block))
			return (errno);
	}
	else if (chdir(block->argv->next->content))
		return (errno);
	dir = getcwd(NULL, 0);
	export_env(ft_strjoin("PWD=", dir), ft_strjoin("OLDPWD=", pwd));
	free(dir);
	return (0);
}
