/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:52:40 by junekim           #+#    #+#             */
/*   Updated: 2022/09/17 20:07:02 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_end(char c, char *end, int *quotes)
{
	if (!c || quotes[0] || quotes[1])
		return (1);
	while (*end)
	{
		if (c == *end)
			return (1);
		end++;
	}
	return (0);
}

int	is_space(char ch)
{
	if (ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f'
		|| ch == '\r' || ch == ' ')
		return (1);
	return (0);
}

int	ft_strlen(char *str, char *end)
{
	int	len;
	int	quotes[2];

	len = 0;
	quotes[0] = 0;
	quotes[1] = 0;
	if (*str == )
	while (is_end(*str, end, quotes))
	{
		if (!quotes[0] && !quotes[0] && !is_end(*str, end))
		{
			len++;
			str++;
		}
	}
	return (len);
}

char	*ft_dup(char *str, char *end)
{
	int		len;
	int		i;
	char	*result;

	len = 0;
	i = 0;
	len = ft_strlen(str, end);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!(result))
		return (NULL);
	while (i < len)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

