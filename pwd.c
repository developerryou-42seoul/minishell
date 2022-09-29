/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:42:35 by junekim           #+#    #+#             */
/*   Updated: 2022/09/29 17:46:49 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

int	pwd(void)
{
	char	*dir;

	dir = getcwd(NULL, 0);
	if (!dir)
		error(strerror(errno));
	printf("%s\n", dir);
	free(dir);
	return (1);
}
