/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:38:50 by junekim           #+#    #+#             */
/*   Updated: 2022/10/04 17:38:51 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parent_signal(int signum)
{
	if (signum == SIGINT)
	{
		printf("mini-0.0$ \n");
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
		g_data->past_return = 1;
	}
}

void	child_signal(int signum)
{
	if (signum == SIGINT)
		printf("\n");
	if (signum == SIGQUIT)
		printf("Quit: 3\n");
}

void	set_terminal(struct termios *t)
{
	signal(SIGINT, parent_signal);
	signal(SIGQUIT, SIG_IGN);
	tcgetattr(STDIN_FILENO, t);
	t->c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, t);
}

void	reset_terminal(struct termios *t)
{
	signal(SIGINT, child_signal);
	signal(SIGQUIT, child_signal);
	tcgetattr(STDIN_FILENO, t);
	t->c_lflag |= ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, t);
}

void	redir_terminal(struct termios *t)
{
	signal(SIGINT, SIG_DFL);
	siganl(SIGQUIT, SIG_IGN);
	tcgetattr(STDIN_FILENO, t);
	t->c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, t);
}