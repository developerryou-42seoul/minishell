/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:42:35 by junekim           #+#    #+#             */
/*   Updated: 2022/09/29 21:15:37 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_pwd(t_block *block)
{
	char	*dir;

	if (block->argc != 1)
		return (1);
	dir = getcwd(NULL, 0);
	if (!dir)
		return (errno);
	printf("%s\n", dir);
	free(dir);
	return (0);
}
