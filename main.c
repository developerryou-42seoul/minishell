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

int	main(int argc, char **argv, char **envp)
{
	char			*line;
	struct termios	t;
	t_block_info	info;

	init_g_data(envp);
	while (1)
	{
		set_terminal(&t);

		info.head = NULL;
		info.tail = NULL;
		line = readline("mini-0.0$ ");
		if (line)
		{
			if (*line)
				add_history(line);
			reset_terminal(&t);
			parser(line, &info);
			excute(&info);
			chdir(find_env("$PWD", g_data->envp, 1));
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
