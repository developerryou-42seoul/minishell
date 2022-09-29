/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:40:44 by junekim           #+#    #+#             */
/*   Updated: 2022/09/29 21:25:17 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	process_sigint(int signum)
{
	if (signum == SIGINT)
		printf("\n");
}

void	setting_signal(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTERM, SIG_IGN);
}

void	process_signal(void)
{
	signal(SIGINT, process_sigint);
}

int	main(int argc, char **argv, char **envp)
{
	char			*line;
	struct termios	t;
	t_block_info	info;

	init_g_data(envp);
	init_terminal(&t);
	while (1)
	{
		setting_signal();
		info.head = NULL;
		info.tail = NULL;
		line = readline("mini-0.0$ ");
		if (line)
		{
			if (*line)
				add_history(line);
			parser(line, &info);
			process_signal();
			excute(&info);
			chdir(find_env("$PWD", data->envp, 1));
		}
		else
		{
			printf("exit\n");
			exit(1);
		}
		free(line);
		free_info(&info);
	}
	(void)argc;
	(void)argv;
	return (0);
}
