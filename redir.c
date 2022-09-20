/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:38:07 by junekim           #+#    #+#             */
/*   Updated: 2022/09/20 13:07:47 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_redir(t_block *block, char *line)
{
	if (is_in_quote(block))
		return (0);
	if (*line == '>')
	{
		if (*(line + 1) == '>')
			return (4);
		return (2);
	}
	else if (*line == '<')
	{
		if (*(line + 1) == '<')
			return (3);
		return (1);
	}
	return (0);
}
