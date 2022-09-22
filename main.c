/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:40:44 by junekim           #+#    #+#             */
/*   Updated: 2022/09/22 18:07:15 by junekim          ###   ########seoul.kr  */
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

int	main(int argc, char **argv, char **envp)
{
	char			*line;
	struct termios	t;
	t_block_info	info;

	init_terminal(&t);
	setting_signal();
	while (1)
	{
		//must free act
		info.head = NULL;
		info.tail = NULL;
		line = readline("mini-0.0$ ");
		if (line)
		{
			if (*line)
				add_history(line);
			parser(line, &info);
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
