/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:55:56 by junekim           #+#    #+#             */
/*   Updated: 2022/10/04 19:11:44 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_space(t_block *block, char ch)
{
	if (is_in_quote(block))
		return (0);
	if (ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f'
		|| ch == '\r' || ch == ' ')
		return (1);
	return (0);
}

int	is_same_str(char *s1, char *s2)
{
	if (ft_strlen(s1) == ft_strlen(s2) && \
	ft_strncmp(s1, s2, ft_strlen(s1)) == 0)
		return (1);
	return (0);
}

int	is_esr(t_block *block, char **line)
{
	return (!is_end(block, **line) && !is_space(block, **line) \
			&& !is_redir(block, *line));
}

int	is_redir(t_block *block, char *line)
{
	if (is_in_quote(block))
		return (0);
	if (*line == '>')
	{
		if (*(line + 1) == '>')
			return (4);
		return (2);
	}
	else if (*line == '<')
	{
		if (*(line + 1) == '<')
			return (3);
		return (1);
	}
	return (0);
}
