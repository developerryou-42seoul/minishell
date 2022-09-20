/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 19:36:43 by junekim           #+#    #+#             */
/*   Updated: 2022/09/20 17:33:36 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_info(t_block_info *info)
{
	t_block	*cur;
	int		i;

	i = 1;
	cur = info->head;
	if (!cur)
		return ;
	while (cur)
	{
		printf("$$$block %d$$$\n", i);
		print_block(cur);
		cur = cur->next;
		i++;
	}
	printf("\n");
}

void	print_block(t_block *block)
{
	t_list	*cur;

	cur = block->argv;
	printf("***argv***\n");
	while (cur)
	{
		printf("%s\n", cur->string);
		cur = cur->next;
	}
	cur = block->redir;
	printf("***redir***\n");
	while (cur)
	{
		if (cur->type == 1)
			printf("< ");
		else if (cur->type == 2)
			printf("> ");
		else if (cur->type == 3)
			printf("<< ");
		else if (cur->type == 4)
			printf(">> ");
		printf("%s\n", cur->string);
		cur = cur->next;
	}
}
