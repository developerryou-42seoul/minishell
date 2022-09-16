/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 10:31:17 by junekim           #+#    #+#             */
/*   Updated: 2022/09/16 14:46:00 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	cursor_position(int *col, int *row)
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

static int	cursor_putchar(int ch, int *col, int *row)
{
	int	ret;

	ret = 0;
	if (ch == KEY_LEFT)
		ret = left(col, row);
	else if (ch == KEY_RIGHT)
		ret = right(col, row);
	else if (ch == KEY_UP)
		ret = up(col, row);
	else if (ch == KEY_DOWN)
		ret = down(col, row);
	else if (ch == KEY_BACKSPACE)
		ret = backspace(col, row);
	else
	{
		(*col)++;
		ret = ft_putchar(ch);
	}
	return (ret);
}

int	parse_char(void)
{
	int	ret;
	int	ch;
	int	col;
	int	row;

	ret = read(STDIN_FILENO, &ch, sizeof(ch));
	if (ret < 0)
		return (1);
	while (ret)
	{
		if (cursor_position(&col, &row))
			return (1);
		if (cursor_putchar(ch, &col, &row))
			return (1);
		ch = 0;
		ret = read(STDIN_FILENO, &ch, sizeof(ch));
		if (ret < 0)
			return (1);
	}
	return (0);
}
