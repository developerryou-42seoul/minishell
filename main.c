/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:40:44 by junekim           #+#    #+#             */
/*   Updated: 2022/09/16 10:27:34 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_path(char **envp)
{
	while (strncmp("PATH", *envp, 4)) //ft_strncmp
		envp++;
	return (*envp + 5);
}

void	signal_handler(int signum)
{
	if (signum == SIGINT)
	{
		printf("mini-0.0$ \n");
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

void	setting_signal(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTERM, SIG_IGN);
	//signal(SIG@@), SIG_IGN);
}

int main(int argc, char **argv, char **envp)
{
	char			*line;
	struct termios	t;

	init_terminal(&t);
	setting_signal();
	while (1)
	{
		line = readline("mini-0.0$ ");
		if (line)
		{
			if (*line != '\0')
				add_history(line);
			printf("%c", *line);
//			line_execute(line, @@, );
		}
		else
			exit(1);
		free(line);
	}
	(void)argc;
	(void)argv;
	(void)envp;
	return (0);
}

int		main(void)
{
	struct termios		t;

	if (!init_term(&t) || !init_query() || !read_char())
		return (1);
	return (0);
}