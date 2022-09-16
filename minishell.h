/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 10:32:32 by junekim           #+#    #+#             */
/*   Updated: 2022/09/16 14:29:45 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define KEY_LEFT		4479771
# define KEY_RIGHT		4414235
# define KEY_UP			4283163
# define KEY_DOWN		4348699
# define KEY_BACKSPACE	127

# include "./libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <termcap.h>
# include <sys/termios.h>
# include <readline/readline.h>
# include <readline/history.h>

const char	*g_cm;
const char	*g_ce;
const char	*g_dc;

int	up(int *col, int *row);
int	down(int *col, int *row);
int	left(int *col, int *row);
int	right(int *col, int *row);
int	backspace(int *col, int *row);

int	parse_char(void);

int	init_terminal(struct termios *t);
int	ft_putchar(int ch);

#endif
