/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:56:57 by junekim           #+#    #+#             */
/*   Updated: 2022/09/20 12:45:40 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_quote(char ch)
{
	if (ch == 39)
		return (1);
	else if (ch == 34)
		return (2);
	else
		return (0);
}

int	is_in_quote(t_block *block)
{
	return (block->quote[0] || block->quote[1]);
}

int	quote(t_block *block, char ch)
{
	int	type;

	type = is_quote(ch);
	if (!type)
		return (0);
	if (!block->quote[0] && !block->quote[1])
	{
		block->quote[type - 1] = 1;
		return (1);
	}
	else if (block->quote[type - 1] == 1)
	{
		block->quote[type - 1] = 0;
		return (1);
	}
	return (0);
}
