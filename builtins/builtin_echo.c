/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:35:07 by junekim           #+#    #+#             */
/*   Updated: 2022/10/04 17:35:08 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	check_flag(t_list *curr)
{
	char	*argv;
	int		flag;
	size_t	i;

	argv = (char *)curr->content;
	flag = 0;
	i = 2;
	if (argv[0] == '-' && argv[1] == 'n')
	{
		flag = 1;
		while (i < ft_strlen(argv))
		{
			if (argv[i] != 'n' && argv[i] != '\0')
			{
				flag = 0;
				break ;
			}
			i++;
		}
	}
	return (flag);
}

int	builtin_echo(t_block *block)
{
	t_list	*curr;
	size_t	flag;

	curr = block->argv->next;
	flag = check_flag(curr);
	if (flag == 1)
		curr = curr->next;
	while (curr)
	{
		printf("%s", (char *)curr->content);
		if (curr->next)
			printf(" ");
		curr = curr->next;
	}
	if (flag == 0)
		printf("\n");
	return (0);
}
