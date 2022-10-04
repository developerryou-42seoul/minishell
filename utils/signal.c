#include "minishell.h"

void	parent_signal(int signum)
{
	if (signum == SIGINT)
	{
		printf("mini-0.0$ \n");
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
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