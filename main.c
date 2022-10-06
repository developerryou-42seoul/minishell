/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:40:44 by junekim           #+#    #+#             */
/*   Updated: 2022/10/06 20:55:28 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	input_line(char *line, t_block_info *info)
{
	char	*chaged_line;

	if (*line)
		add_history(line);
	reset_terminal(&g_data->t);
	chaged_line = change_dollar(line);
	if (parser(chaged_line, info))
		return ;
	excute(info);
	chdir(find_env("$PWD", g_data->envp, 1));
	free(chaged_line);
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
	}
	(void)argc;
	(void)argv;
	return (0);
}
