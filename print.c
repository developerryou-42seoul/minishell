/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 19:36:43 by junekim           #+#    #+#             */
/*   Updated: 2022/09/17 19:39:49 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_block(t_block *block)
{
	t_list	*cur;

	cur = block->argv;
	while (cur)
	{
		printf("%s ", cur->string);
		cur = cur->next;
	}
	printf("\n");
}
