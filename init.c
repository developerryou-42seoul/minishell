/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:07:09 by junekim           #+#    #+#             */
/*   Updated: 2022/09/16 09:47:05 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_terminal(struct termios *t)
{
	tcgetattr(STDIN_FILENO, t);
	t->c_lflag &= ~(ICANON | ECHO);
	t->c_cc[VMIN] = 1;
	t->c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, t);
	if (!tgetent(NULL, "xterm"))
		return (1);
	g_cm = tgetstr("cm", NULL);
	g_ce = tgetstr("ce", NULL);
	g_dc = tgetstr("dc", NULL);
	if (!g_cm || !g_ce || !g_dc)
		return (1);
	return (0);
}

