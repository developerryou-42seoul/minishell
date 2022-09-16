/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:00:17 by junekim           #+#    #+#             */
/*   Updated: 2022/09/16 14:46:15 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	up(int *col, int *row)
{
	if (*row)
	{
		(*row)--;
		if (tputs(tgoto(g_cm, *col, *row), 1, ft_putchar))
			return (1);
	}
	return (0);
}

int	down(int *col, int *row)
{
	(*row)++;
	if (tputs(tgoto(g_cm, *col, *row), 1, ft_putchar))
		return (1);
	return (0);
}

int	left(int *col, int *row)
{
	if (*col)
	{
		(*col)--;
		if (tputs(tgoto(g_cm, *col, *row), 1, ft_putchar))
			return (1);
	}
	return (0);
}

int	right(int *col, int *row)
{
	(*col)++;
	if (tputs(tgoto(g_cm, *col, *row), 1, ft_putchar))
		return (1);
	return (0);
}

int	backspace(int *col, int *row)
{
	if (*col)
	{
		(*col)--;
		if (tputs(tgoto(g_cm, *col, *row), 1, ft_putchar))
			return (1);
	}
	if (tputs(g_dc, 1, ft_putchar))
		return (1);
	return (0);
}
