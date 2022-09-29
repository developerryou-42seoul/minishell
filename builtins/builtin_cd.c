/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:17:41 by junekim           #+#    #+#             */
/*   Updated: 2022/09/29 21:10:43 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	init_env(char **dir, char **pwd, char **oldpwd, char **home)
{
	*dir = getcwd(NULL, 0);
	if (!dir)
		return (errno);
	*pwd = find_env("$PWD", data->envp, 0);
	*oldpwd = find_env("$OLDPWD", data->envp, 0);
	*home = find_env("$HOME", data->envp, 0);
	if (!(*pwd) || !(*oldpwd) || !(*home))
		return (1);
	return (0);
}

int	builtin_cd(t_block *block)
{
	int		ret;
	char	*dir;
	char	*pwd;
	char	*oldpwd;
	char	*home;

	if (block->argc > 2)
		return (1);
	ret = init_env(&dir, &pwd, &oldpwd, &home);
	if (chdir(block->argv->next->content))
		return (errno);
	if (ret)
		return (ret);
	dir = getcwd(NULL, 0);
	printf("%s\n", dir);
	free(dir);
	return (0);
}
