/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:52:40 by junekim           #+#    #+#             */
/*   Updated: 2022/10/06 21:19:03 by sryou            ###   ########.fr       */
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
		error("malloc error");
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

char	*mini_join_dollar(char *str)
{
	int		i;
	char	*ret;

	i = 0;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!ret)
		error("malloc error");
	ret[0] = '$';
	while (str[i])
	{
		ret[i + 1] = str[i];
		i++;
	}
	ret[i + 1] = '\0';
	return (ret);
}

char	*mini_join_str(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ret)
		error("malloc error");
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[j])
		ret[i++] = s2[j++];
	ret[i] = '\0';
	free(s1);
	return (ret);
}

int	is_end(t_block *block, char ch)
{
	if (!ch)
		return (1);
	if (is_in_quote(block))
		return (0);
	else if (ch == '|')
		return (1);
	return (0);
}

void	create_empty(char **str)
{
	*str = (char *)malloc(sizeof(char));
	if (!(*str))
		error("create_empty");
	(*str)[0] = '\0';
	return ;
}
