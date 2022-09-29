/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:17:41 by junekim           #+#    #+#             */
/*   Updated: 2022/09/29 19:04:31 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_cd(t_block *block)
{
	char	*dir;
	char	*home;

	if (block->argc <= 2)
		return (1);
	dir = getcwd(NULL, 0);
	home = find_env("HOME", data->envp);
	if (!dir)
		return (errno);
	printf("%s\n", dir);
	free(dir);
	return (0);
}
