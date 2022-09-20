/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:52:40 by junekim           #+#    #+#             */
/*   Updated: 2022/09/20 13:44:16 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*mini_join(char *str, char ch)
{
	int		i;
	char	*ret;

	i = 0;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!ret)
	{
		free(str);
		return (NULL);
	}
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i++] = ch;
	ret[i] = '\0';
	free(str);
	return (ret);
}

int	is_space(t_block *block, char ch)
{
	if (block->quote[0] || block->quote[1])
		return (0);
	if (ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f'
		|| ch == '\r' || ch == ' ')
		return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

void	create_empty(char **str)
{
	*str = (char *)malloc(sizeof(char));
	if (!(*str))
		error();
	(*str)[0] = '\0';
	return ;
}
