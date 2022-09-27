/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 19:36:43 by junekim           #+#    #+#             */
/*   Updated: 2022/09/26 17:28:23 by sryou            ###   ########.fr       */
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
	t_redir	*redir;

	cur = block->argv;
	printf("***argv***\n");
	while (cur)
	{
		printf("%s\n", cur->content);
		cur = cur->next;
	}
	cur = block->redir;
	printf("***redir***\n");
	while (cur)
	{
		redir = cur->content;
		if (redir->type == 1)
			printf("< ");
		else if (redir->type == 2)
			printf("> ");
		else if (redir->type == 3)
			printf("<< ");
		else if (redir->type == 4)
			printf(">> ");
		printf("%s\n", redir->string);
		cur = cur->next;
	}
}
