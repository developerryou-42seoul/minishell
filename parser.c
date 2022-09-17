/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:45:36 by junekim           #+#    #+#             */
/*   Updated: 2022/09/17 19:52:21 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parser(char *line, t_block_info *info)
{
	t_block	*block;
	char	*str;
	int		i;

	block = (t_block *)malloc(sizeof(t_block));
	add_block(info, block);

	while (*line)
	{
		is_
		i += ft_strlen(line[i])
		line[i];
	}
	add_argv(block, ft_dup(line, "><"));
	print_block(block);
	return (0);
}
