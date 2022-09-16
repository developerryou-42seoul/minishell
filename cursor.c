/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 10:31:17 by junekim           #+#    #+#             */
/*   Updated: 2022/09/16 10:38:15 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_cursor_pos(int *col, int *row)
{
	int					i;
	int					ret;
	char				buf[256];

	write(STDOUT_FILENO, "\033[6n", 4);
	ret = read(STDIN_FILENO, buf, 256);
	if (ret < 0)
		return (1);
	buf[ret] = '\0';
	i = 0;
	while (!ft_isdigit(buf[i]))
		++i;
	*row = ft_atoi(&buf[i]) - 1;
	while (ft_isdigit(buf[i]))
		++i;
	while (!ft_isdigit(buf[i]))
		++i;
	*col = ft_atoi(&buf[i]) - 1;
	return (0);
}

int	cur_left(int *col, int *row)
{
	if (*col)
	{
		(*col)--;
		if (tputs(tgoto(g_cm, *col, *row), 1, ft_putchar))
			return (1);
	}
	return (0);
}

int	cur_right(int *col, int *row)
{
	(*col)++;
	if (tputs(tgoto(g_cm, *col, *row), 1, ft_putchar))
		return (1);
	return (0);
}

int	cur_up(int *col, int *row)
{
	if (*row)
	{
		(*row)--;
		if (tputs(tgoto(g_cm, *col, *row), 1, ft_putchar))
			return (1);
	}
	return (0);
}

int	cur_down(int *col, int *row)
{
	(*row)++;
	if (tputs(tgoto(g_cm, *col, *row), 1, ft_putchar))
		return (1);
	return (0);
}

int	cur_backspace(int *col, int *row)
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

bool	key_handle(int ch, int *col, int *row)
{
	if (ch == KEY_LEFT)
	{
		if (!cur_left(col, row))
			return (false);
	}
	else if (ch == KEY_RIGHT)
	{
		if (!cur_right(col, row))
			return (false);
	}
	else if (ch == KEY_UP)
	{
		if (!cur_up(col, row))
			return (false);
	}
	else if (ch == KEY_DOWN)
	{
		if (!cur_down(col, row))
			return (false);
	}
	else if (ch == KEY_BACKSPACE)
	{
		if (!cur_backspace(col, row))
			return (false);
	}
	else
	{
		++(*col);
		if (!putchar(ch))
			return (false);
	}
	return (true);
}

bool	read_char(void)
{
	int					ch;
	int					ret;
	int					col;
	int					row;

	ret = read(STDIN_FILENO, &ch, sizeof(ch));
	if (ret < 0)
		return (1);
	while (ret)
	{
		if (get_position(&col, &row))
			return (1);
		ret = read(STDIN_FILENO, &ch, sizeof(ch));
		if (ret < 0)
			return (1);
		if (key_handle(ch, &col, &row))
			return (false);
		ch = 0;
	}
}