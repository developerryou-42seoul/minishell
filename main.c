/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:40:44 by junekim           #+#    #+#             */
/*   Updated: 2022/10/04 19:44:49 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	input_line(char *line, t_block_info *info)
{
	if (*line)
		add_history(line);
	reset_terminal(&g_data->t);
	parser(line, info);
	excute(info);
	chdir(find_env("$PWD", g_data->envp, 1));
}

int	main(int argc, char **argv, char **envp)
{
	char			*line;
	t_block_info	info;

	init_g_data(envp);
	while (1)
	{
		set_terminal(&g_data->t);
		info.head = NULL;
		info.tail = NULL;
		line = readline("mini-0.0$ ");
		if (line)
			input_line(line, &info);
		else
		{
			printf("exit\n");
			exit(1);
		}
		free(line);
		free_info(&info);
		system("leaks minishell");
	}
	(void)argc;
	(void)argv;
	return (0);
}
