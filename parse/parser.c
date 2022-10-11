/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnam <jnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:45:36 by junekim           #+#    #+#             */
/*   Updated: 2022/10/11 15:02:13 by jnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*parser_sub(char *line, t_block_info *info)
{
	t_block	*block;

	block = (t_block *)malloc(sizeof(t_block));
	if (!block)
		error(strerror(errno));
	add_block(info, block);
	while (!is_end(block, *line))
	{
		if (is_space(block, *line))
		{
			line++;
			continue ;
		}
		while (!is_end(block, *line) && !is_space(block, *line))
		{
			if (read_block(&line, info))
				return (NULL);
			if (is_in_quote(block))
			{
				error_print(strerror(errno), "");
				return (NULL);
			}
		}
	}
	return (line);
}

int	parser(char *line, t_block_info *info)
{
	while (*line)
	{
		while (*line == '\t' || *line == '\n' || *line == '\v' || *line == '\f' \
		|| *line == '\r' || *line == ' ')
			line++;
		if (*line == '|')
		{
			ft_putstr_fd("mini: syntax error near unexpected token `|'\n", 2);
			return (1);
		}
		line = parser_sub(line, info);
		if (!line)
			return (1);
		if (*line == '|')
		{
			line ++;
			if (*line == '|' || *line == '\0')
			{
				ft_putstr_fd("mini: syntax error near unexpected token `|'\n", 2);
				return (1);
			}
		}
	}
	return (0);
}
